#ifndef PRODUCT_H
#define PRODUCT_H

#include "operator.h"

class Product : public Operator
{
public:
    Product();
    Product(Expression *lOpPt, Expression *rOpPt);
    Product(list<Assignement *> *assignements, Expression *lOpPt, Expression *rOpPt);
    float calculate() override;
};


//French translation
typedef Product Multiplication;

#endif // PRODUCT_H
