#ifndef SUM_H
#define SUM_H

#include "operator.h"

class Sum : public Operator
{
public:
    Sum();
    Sum(Expression *lOpPt, Expression *rOpPt);
    float calculate() const override;
};


//French translation
typedef Sum Addition;

#endif // SUM_H
