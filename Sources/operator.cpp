#include "../Headers/operator.h"

Operator::Operator(): _lOpPt(NULL), _rOpPt(NULL), _operator("***undefined***")
{

}

bool Operator::calculable()
{
    if(operable())
        //Walkaround for division by 0 detection
        return _lOpPt -> calculable() && _rOpPt -> calculable() && (_operator != "/" || _rOpPt -> calculate() != 0.0);
    else return false;
}

bool Operator::operable()
{
    return _lOpPt != NULL && _rOpPt != NULL;
}

void Operator::displayN(ostringstream &stream)
{
    if(!operable())
    {
        stream << "Display error";
        return;
    }
    stream << "(";
    _lOpPt -> displayN(stream);
    stream << _operator;
    _rOpPt -> displayN(stream);
    stream << ")";
}

void Operator::displayPin(ostringstream &stream)
{
    if(!operable())
    {
        stream << "Display error";
        return;
    }
    _lOpPt -> displayPin(stream);
    _rOpPt -> displayPin(stream);
    stream << _operator;
}
