#include "../Headers/substraction.h"

#include <iostream>

using namespace std;

Substraction::Substraction()
{
    _operator = "-";
}

Substraction::Substraction(Expression *lOpPt, Expression *rOpPt)
{
    _lOpPt = lOpPt;
    _rOpPt = rOpPt;
    _operator = "-";
    _assignements = new list<Assignement *>;
}

Substraction::Substraction(list<Assignement *> *assignements, Expression *lOpPt, Expression *rOpPt)
{
    _lOpPt = lOpPt;
    _rOpPt = rOpPt;
    _operator = "-";
    _assignements = assignements;
}

float Substraction::calculate()
{
    if(calculable())
        return _lOpPt -> calculate() - _rOpPt -> calculate();
    else
    {
        // << "calculation error";
        return 0.0;
    }
}
