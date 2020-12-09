#include "../Headers/assignement.h"

Assignement::Assignement(string name, float value): _name(name), _value(value)
{

}

string Assignement::getName() const
{
    return _name;
}

float Assignement::getValue() const
{
    return _value;
}

bool Assignement::setValue(float value)
{
    _value = value;
    return true;
}
