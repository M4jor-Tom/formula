#include "../Headers/value.h"

Value::Value(float value): _value(value), interpretation(VALUE)
{

}

Value::Value(string name): _name(name), interpretation(NAME)
{

}

Value::Value(string name, float value): _value(value), _name(name), interpretation(BOTH)
{

}

bool Value::calculable()
{
    return interpretation == BOTH || interpretation == VALUE;
}

float Value::calculate()
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
    if(interpretation == NAME || interpretation == BOTH)
        interpretation = BOTH;
    else if(interpretation != VALUE)
        return false;

    return true;
}

string Value::getRepresentation()
{
    stringstream ret;
    switch(interpretation)
    {
        case BOTH:
            ret << "{" << _name << " = ";
        case VALUE:
            ret << _value;
            if(interpretation == BOTH)
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

void Value::displayN(ostringstream &stream)
{
    stream << getRepresentation();
}

void Value::displayPin(ostringstream &stream)
{
    stream << getRepresentation() << " ";
}
