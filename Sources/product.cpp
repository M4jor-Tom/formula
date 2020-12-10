#include "../Headers/product.h"

#include <iostream>

using namespace std;

Product::Product()
{
    _operator = "x";
}

Product::Product(Expression *lOpPt, Expression *rOpPt)
{
    _lOpPt = lOpPt;
    _rOpPt = rOpPt;
    _operator = "x";
    _assignements = new list<Assignement *>;
}

Product::Product(list<Assignement *> *assignements, Expression *lOpPt, Expression *rOpPt)
{
    _lOpPt = lOpPt;
    _rOpPt = rOpPt;
    _operator = "-";
    _assignements = assignements;
}

float Product::calculate()
{
    if(calculable())
        return _lOpPt -> calculate() * _rOpPt -> calculate();
    else
    {
        // << "calculation error";
        return 0.0;
    }
}
