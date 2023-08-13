#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>

#include "Server.hpp"

enum {
    max_listen_count = 10
};

Server* Server::Init(int _port, EventSelector* _the_selector)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == fd)
        return 0;

    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    addr.sin_addr.s_addr = htons(INADDR_ANY);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(_port);

    if (-1 == bind(fd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in)))
        return 0;

    if (-1 == listen(fd, max_listen_count))
        return 0;

    return new Server(_port, true, false, _the_selector);
}

Server::~Server()
{
    while (first) {
        session_item *tmp = first->next;
        delete first->s;
        delete first;
        first = tmp;
    }
}

void Server::Handle(bool r, bool w)
{
    if (!r)
        return;

    struct sockaddr_in addr;
    socklen_t len;
    int _fd = accept(GetFd(), (struct sockaddr*)&addr, &len);
    if (_fd == -1)
        return;

    session_item *tmp = new session_item;
    tmp->s = 0;                             // FIXIT - remove NULL addres
    tmp->next = first;
    first = tmp;

    master->Add(tmp->s);
}
