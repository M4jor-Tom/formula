#ifndef DIVISION_H
#define DIVISION_H

#include "operator.h"

class Division : public Operator
{
public:
    Division();
    Division(Expression *lOpPt, Expression *rOpPt);
    //bool calculable() override;
    float calculate() const override;
};

#endif // DIVISION_H
