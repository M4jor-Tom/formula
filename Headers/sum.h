#ifndef SUM_H
#define SUM_H

#include "operator.h"

class Sum : public Operator
{
public:
    Sum();
    Sum(Expression *lOpPt, Expression *rOpPt);
    float calculate() override;
};

#endif // SUM_H
