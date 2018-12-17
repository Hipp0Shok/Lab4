#include "test.h"
#include <string>

Test::Test()
{}

Test::Test(time_t& deadline, std::string& subject, int& difficulty, std::string& name,  std::string& topic):
    Deadline::Deadline(deadline, subject, difficulty, name),
    _topic(topic != "" ? topic : "None")
{
}

Test::Test(Test const & existing):
    Deadline::Deadline(existing),
    _topic(existing._topic)
{
}
Test::~Test()
{

}
