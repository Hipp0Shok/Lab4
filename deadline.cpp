#include "deadline.h"
#include <time.h>
#include <string>

Deadline::Deadline():
    _deadline(time(nullptr)),
    _subject("None"),
    _name("Sample work"),
    _difficulty(5),
    _isDone(false)
{
}

Deadline::Deadline(time_t &deadline, std::string &subject, int &difficulty, std::string &name):
    _deadline(deadline > 0 ? deadline : time(nullptr)),
    _subject(subject != "" ? subject : "None"),
    _name(name != "" ? name : "Sample work"),
    _difficulty(difficulty >= 0 && difficulty <= 10 ? difficulty : 5),
    _isDone(false)
{

}

Deadline::Deadline(Deadline const &existing):
    _deadline(existing._deadline),
    _subject(existing._subject),
    _name(existing._name),
    _difficulty(existing._difficulty),
    _isDone(existing._isDone)
{
}

Deadline::~Deadline()
{
}

int Deadline::getDifficulty() const
{
    return _difficulty;
}

std::string Deadline::getSubject() const
{
    return _subject;
}

time_t Deadline::getDeadline() const
{
    return _deadline;
}

void Deadline::setDifficulty(int const &difficulty)
{
    if(difficulty >= 0 && difficulty <= 10)
    {
        _difficulty = difficulty;
    }
}

void Deadline::setSubject(std::string const &subject)
{
    if(subject != "")
    {
        _subject = subject;
    }
}

void Deadline::setDeadline(time_t const &deadline)
{
    _deadline = deadline;
}

void Deadline::update()
{
    if(isExpired())
    {
        setAsDone();
    }
}

bool Deadline::isExpired() const
{
    if()
    return  true;
}