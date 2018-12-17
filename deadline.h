#ifndef DEADLINE_H
#define DEADLINE_H
#include <string>
#include <time.h>

class Deadline
{
public:
    Deadline();
    Deadline(time_t&, std::string&, int&, std::string&);
    Deadline(Deadline const &);
    virtual ~Deadline() = 0;
    virtual bool isExpired() const;
    virtual int getDifficulty() const;
    virtual std::string getSubject() const;
    virtual time_t getDeadline() const;
    virtual void setDifficulty(int const &);
    virtual void setSubject(std::string const &);
    virtual void setDeadline(time_t const &);
    virtual void setAsDone();
    virtual void update();
protected:
    time_t _deadline;
    std::string _subject, _name;
    int _difficulty;
    bool _isDone;
};


#endif // DEADLINE_H