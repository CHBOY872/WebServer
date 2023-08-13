#include <unistd.h>

#include "FdHandler.hpp"
#include "EventSelector.hpp"

FdHandler::FdHandler(int _fd, bool _want_read, bool _want_write) 
    : fd(_fd), want_read(_want_read), want_write(_want_write) {}
FdHandler::~FdHandler() { close(fd); }