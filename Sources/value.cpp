#include "../Headers/value.h"

Value::Value(float value): _value(value), _interpretation(VALUE)
{

}

Value::Value(string name): _name(name), _interpretation(NAME)
{

}

Value::Value(string name, float value): _value(value), _name(name), _interpretation(BOTH)
{

}

Value::Value(const Value &v): _value(v._value), _name(v._name), _interpretation(v._interpretation)
{

}

bool Value::calculable() const
{
    return _interpretation == BOTH || _interpretation == VALUE;
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

    //Interpretation of object changed
    if(_interpretation == NAME || _interpretation == BOTH)
        _interpretation = BOTH;
    else if(_interpretation != VALUE)
        return false;

    return true;
}

string Value::getRepresentation() const
{
    stringstream ret;
    switch(_interpretation)
    {
        case BOTH:
            ret << "{" << _name << " = ";
        case VALUE:
            ret << _value;
            if(_interpretation == BOTH)
                ret << "}";
            break;

        case NAME:
            ret << _name;
            break;

        default:
            ret << "Value Interpretation Error";
    }
    return ret.str();
}

string Value::getName() const
{
    return _name;
}

void Value::displayN(ostringstream &stream) const
{
    stream << getRepresentation();
}

void Value::displayPin(ostringstream &stream) const
{
    stream << getRepresentation() << " ";
}
