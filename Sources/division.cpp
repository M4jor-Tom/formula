#include "../Headers/division.h"

#include <iostream>

using namespace std;

Division::Division()
{
    _operator = "/";
}

Division::Division(Expression *lOpPt, Expression *rOpPt)
{
    _lOpPt = lOpPt;
    _rOpPt = rOpPt;
    _operator = "/";
}

float Division::calculate()
{
    if(operable())
        return _lOpPt -> calculate() / _rOpPt -> calculate();
    else
    {
        // << "calculation error";
        return 0.0;
    }
}
