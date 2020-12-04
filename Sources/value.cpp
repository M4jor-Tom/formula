#include "../Headers/value.h"

Value::Value(float value): _value(value)
{

}

float Value::calculate()
{
    return _value;
}

void Value::displayN(ostringstream &stream)
{
    stream << _value;
}

void Value::displayPin(ostringstream &stream)
{
    stream << _value << " ";
}
