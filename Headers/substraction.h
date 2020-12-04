#ifndef SUB_H
#define SUB_H

#include "operator.h"

class Substraction : public Operator
{
public:
    Substraction();
    Substraction(Expression *lOpPt, Expression *rOpPt);
    float calculate() override;
};

#endif // SUB_H
