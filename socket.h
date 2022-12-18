#pragma once

#include <mutex>
#include <queue>
#include <condition_variable>

class Socket_Queue {
public:
    Socket_Queue()
    {
    }
    void push(int socket);
    int wait_and_pop();

private:
    std::mutex mut{};
    std::queue<int> sockets{};
    std::condition_variable socket_available{};
};
