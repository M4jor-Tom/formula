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


//French translation
typedef Substraction Soustraction;

#endif // SUB_H
