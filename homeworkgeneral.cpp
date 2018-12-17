#include "homeworkgeneral.h"
#include <string>

HomeworkGeneral::HomeworkGeneral():
    Deadline::Deadline(),
    currentCondition(NotStarted),
    currentPriority(Medium)
{
}

HomeworkGeneral::HomeworkGeneral(time_t& deadline, std::string subject, int& difficulty, std::string& name, condition newCondition, priority newPriority):
    Deadline::Deadline(deadline, subject, difficulty, name),
    currentCondition(newCondition >= NotStarted && newCondition <= IsOnCheking ? newCondition : NotStarted),
    currentPriority(newPriority >= Low && newPriority <= High ? newPriority : Medium)
{
}

HomeworkGeneral::HomeworkGeneral(HomeworkGeneral const &existing):
    Deadline::Deadline(existing),
    currentCondition(existing.currentCondition),
    currentPriority(existing.currentPriority)
{
}

HomeworkGeneral::~HomeworkGeneral()
{
}

bool HomeworkGeneral::isExpired() const
{
    if(time(nullptr) > _deadline)
    {
        return true;
    }
    return false;
}

void HomeworkGeneral::changePriority(priority newPriority)
{
    if(newPriority >= Low && newPriority <= High)
    {
        currentPriority = newPriority;
    }
}

void HomeworkGeneral::changeCondition(condition newCondition)
{
    if(newCondition >= NotStarted && newCondition <= IsOnCheking)
    {
        currentCondition = newCondition;
    }
}

condition HomeworkGeneral::getCondition() const
{
    return currentCondition;
}

priority HomeworkGeneral::getPriority() const
{
    return currentPriority;
}
