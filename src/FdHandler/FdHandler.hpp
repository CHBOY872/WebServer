#ifndef FDHANDLER_SENTRY
#define FDHANDLER_SENTRY

class FdHandler {
    int fd;
    bool want_read, want_write;
public:
    FdHandler(int _fd, bool _want_read, bool _want_write);
    virtual ~FdHandler();

    bool WantRead() { return want_read; }
    bool WantWrite() { return want_write; }
    int GetFd() { return fd; }

    void SetRead(bool _want_read) { want_read = _want_read; }
    void SetWrite(bool _want_write) { want_write = _want_write; }

    virtual void Handle() = 0;
};

#endif