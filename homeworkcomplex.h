#ifndef HOMEWORKCOMPLEX_H
#define HOMEWORKCOMPLEX_H
#include "homeworkgeneral.h"
#include "list.h"

class HomeworkComplex: public HomeworkGeneral
{
public:
    HomeworkComplex();
    HomeworkComplex(time_t&, std::string, int&, std::string&, std::string&, condition, priority);
    HomeworkComplex(HomeworkComplex &);
    ~HomeworkComplex();
    bool isExpired() const;
    List getParts() const;
    void addPart(HomeworkGeneral const &);
    void deletePart(HomeworkGeneral const &);
private:
    List _parts;
};

#endif // HOMEWORKCOMPLEX_H