#ifndef SUM_H
#define SUM_H

#include "operator.h"

class Sum : public Operator
{
public:
    Sum();
    Sum(Expression *lOpPt, Expression *rOpPt);
    Sum(list<Assignement *> *assignements, Expression *lOpPt, Expression *rOpPt);
    float calculate() override;
};


//French translation
typedef Sum Addition;

#endif // SUM_H
