#ifndef TEST_H
#define TEST_H
#include "deadline.h"
#include <time.h>


class Test: public Deadline
{
public:
    Test();
    Test(time_t&, std::string&, int&,std::string&, std::string&);
    Test(Test const &);
    ~Test();
private:
    std::string _topic;
};


#endif // TEST_H