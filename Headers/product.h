#ifndef PRODUCT_H
#define PRODUCT_H

#include "operator.h"

class Product : public Operator
{
public:
    Product();
    Product(Expression *lOpPt, Expression *rOpPt);
    float calculate() override;
};

#endif // PRODUCT_H
