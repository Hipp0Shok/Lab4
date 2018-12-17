#ifndef HOMEWORKGENERAL_H
#define HOMEWORKGENERAL_H
#include "deadline.h"
enum condition {NotStarted, Started, IsOnCheking};
enum priority {Low, Medium, High};

class HomeworkGeneral: public Deadline
{
public:
    HomeworkGeneral();
    HomeworkGeneral(time_t&, std::string, int&, std::string&, condition, priority);
    HomeworkGeneral(HomeworkGeneral const &);
    virtual ~HomeworkGeneral();
    bool isExpired() const;
    virtual void changePriority(priority);
    virtual void changeCondition(condition);
    virtual condition getCondition() const;
    virtual priority getPriority() const;
protected:
    condition currentCondition;
    priority currentPriority;
};


#endif // HOMEWORKGENERAL_H