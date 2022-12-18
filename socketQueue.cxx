#include "socket.h"

void Socket_Queue::push(int socket)
{
    std::lock_guard<std::mutex> lock{ mut };
    sockets.push(socket);
    socket_available.notify_one();
}

int Socket_Queue::wait_and_pop()
{
    std::unique_lock<std::mutex> lock{ mut };
    socket_available.wait(lock, [this] { return !sockets.empty(); });
    int value = sockets.front();
    sockets.pop();
    return value;
}
