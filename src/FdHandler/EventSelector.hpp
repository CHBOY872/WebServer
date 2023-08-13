#ifndef EVENTSELECTOR_SENTRY
#define EVENTSELECTOR_SENTRY

#include "FdHandler.hpp"

class EventSelector {
    FdHandler **fd_array;
    int fd_array_len;
    int max_fd;

public:
    EventSelector();
    ~EventSelector();

    void Add(FdHandler *h);
    void Remove();
    
    int Run();

private:
    void ReinitArray();
};

#endif