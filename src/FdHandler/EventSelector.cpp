#include "EventSelector.hpp"

enum {
    init_fd_array_len = 32,
};

EventSelector::EventSelector() : fd_array_len(init_fd_array_len), max_fd(-1) 
{
    fd_array = new FdHandler* [init_fd_array_len];
    int i;
    for (i = 0; i < fd_array_len; i++)
        fd_array[i] = 0;
}

EventSelector::~EventSelector()
{
    if (!fd_array)
        return;
    delete[] fd_array;
}

void EventSelector::ReinitArray()
{
    FdHandler **tmp = new FdHandler* [fd_array_len];
    int i;
    for (i = 0; i < fd_array_len; i++)
        tmp[i] = i < max_fd ? fd_array[i] : 0;
    delete[] fd_array;
    fd_array = tmp;
}

void EventSelector::Add(FdHandler *h)
{
    int fd = h->GetFd();
    if (!fd_array || fd > fd_array_len) {
        fd_array_len = init_fd_array_len > fd ? init_fd_array_len : fd + 1;
        ReinitArray(); 
    }
    fd_array[fd] = h;
    if (fd > max_fd)
        max_fd = fd;
}

void EventSelector::Remove(FdHandler *h)
{
    int fd = h->GetFd();
    if (fd >= fd_array_len)
        return;
    fd_array[fd] = 0;
    if (fd == max_fd) {
        for (; max_fd >= 0; max_fd--) {
            if (fd_array[max_fd]) 
                return;
        }
    }
}