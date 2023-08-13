#ifndef SERVER_SENTRY
#define SERVER_SENTRY

#include "../FdHandler/FdHandler.hpp"
#include "../FdHandler/EventSelector.hpp"

class Session;

class Server : public FdHandler {
    struct session_item {
        Session *s;
        session_item *next;
    };

    session_item *first;
    EventSelector *master;

public:
    virtual ~Server();
    static Server* Init(int _port, EventSelector* _the_selector);
    virtual void Handle(bool r, bool w);

private:
    Server(int _fd, bool _want_read, bool _want_write, EventSelector* _master);

};

#endif
