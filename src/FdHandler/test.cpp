#include <stdio.h>
#include <stdlib.h>

#include "EventSelector.hpp"

class TestHandler : public FdHandler
{
public:
    TestHandler(int _fd) : FdHandler(_fd, true, true) {}
    virtual void Handle(bool r, bool w) {}

};

void test1()
{
    TestHandler a(1);
    TestHandler b(3);
    TestHandler c(2);

    EventSelector es;
    es.Add(&a);
    es.Add(&b);
    es.Add(&c);

    if (es.GetMaxFd() != b.GetFd())
        exit(1);
    es.Remove(&b);
    if (es.GetMaxFd() != c.GetFd() && es.GetFdArrayLen() != 2)
        exit(2);
}

int main()
{
    test1();
    return 0;
}
