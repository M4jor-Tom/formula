#include "../Headers/variable.h"

Variable::Variable(string name): Value(0.0), _name(name), _set(false)
{

}

Variable::Variable(string name, float value): Value(value), _name(name), _set(true)
{

}

Variable::Variable(const Variable &v): Value(v._value), _name(v._name), _set(v._set)
{

}

bool Variable::calculable() const
{
    return _set;
}


string Variable::getFormulaRepresentation() const
{
    return _name;
}

string Variable::getRepresentation() const
{
    stringstream ret;
    if(_set)
        ret << "{" <<_name << "=" << _value << "}";
    else
        ret << _name;

    return ret.str();
}

string Variable::getName() const
{
    return _name;
}
