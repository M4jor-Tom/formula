#include "../Headers/operator.h"

Operator::Operator(): _lOpPt(NULL), _rOpPt(NULL), _operator("***undefined***")
{

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
    _lOpPt -> displayN(stream);
    _rOpPt -> displayN(stream);
    stream << _operator;
}
