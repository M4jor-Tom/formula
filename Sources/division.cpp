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
    _assignements = new list<Assignement *>;
}

Division::Division(list<Assignement *> *assignements, Expression *lOpPt, Expression *rOpPt)
{
    _lOpPt = lOpPt;
    _rOpPt = rOpPt;
    _operator = "-";
    _assignements = assignements;
}

float Division::calculate()
{
    if(calculable())
        return _lOpPt -> calculate() / _rOpPt -> calculate();
    else
    {
        // << "calculation error";
        return 0.0;
    }
}
