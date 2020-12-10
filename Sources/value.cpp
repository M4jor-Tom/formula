#include "../Headers/value.h"

Value::Value(float value): _value(value)
{

}

bool Value::calculable() const
{
    return true;
}

float Value::calculate() const
{
    if(calculable())
        //BOTH or VALUE
        return _value;

    //Error (method should not be used)
    return 0.0;
}

bool Value::setValue(float value)
{
    //Value set
    _value = value;

    return true;
}

string Value::getFormulaRepresentation() const
{
    return getRepresentation();
}

string Value::getRepresentation() const
{
    stringstream ret;
    ret << _value;
    return ret.str();
}

void Value::displayN(ostringstream &stream) const
{
    stream << getFormulaRepresentation();
}

void Value::displayPin(ostringstream &stream) const
{
    stream << getFormulaRepresentation() << " ";
}
