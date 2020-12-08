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
