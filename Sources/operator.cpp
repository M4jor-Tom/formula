#include "../Headers/operator.h"

Operator::Operator(): _lOpPt(NULL), _rOpPt(NULL), _operator("***undefined***")
{

}

bool Operator::operable()
{
    return _lOpPt != NULL && _rOpPt != NULL;
}

bool Operator::calculable()
{
    if(operable())
    {
        _lOpPt -> relayAssignements(_assignements);
        _rOpPt -> relayAssignements(_assignements);
        return _lOpPt -> calculable() && _rOpPt -> calculable();
    }
    return false;
}

void Operator::displayN(ostringstream &stream)
{
    if(!operable())
    {
        stream << "Unoperable";
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
        stream << "Unoperable";
        return;
    }
    _lOpPt -> displayPin(stream);
    _rOpPt -> displayPin(stream);
    stream << _operator;
}
