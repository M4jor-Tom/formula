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

/*  //Initial Idea for division by 0
bool Division::calculable()
{
    Operator *beforeInherit = this;

    //Need to use 'calculable' method of 'Operation' before inheritance to 'Division'
    if(beforeInherit -> calculable())
        return _rOpPt -> calculate() != 0.0;

    return false;
}
*/

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
