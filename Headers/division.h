#ifndef DIVISION_H
#define DIVISION_H

#include "operator.h"

class Division : public Operator
{
public:
    Division();
    Division(Expression *lOpPt, Expression *rOpPt);
    Division(list<Assignement *> *assignements, Expression *lOpPt, Expression *rOpPt);
    float calculate() override;
};

#endif // DIVISION_H
