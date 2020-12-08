#include "../Headers/expression.h"

Expression::Expression()
{

}

void Expression::relayAssignements(const list<string> &names, const list<float> &values)
{
    _names = names;
    _values = values;
}

int  Expression::seekVariable(string needle)
{
    unsigned int index = 0;
    for(string name:_names)
        if(name == needle)
            return index;
        else
            index++;
    return -1;
}

bool Expression::newVariable(string name, float value)
{
    if(seekVariable(name) == -1)
    {
        _names.push_back(name);
        _values.push_back(value);
    }
    else
        return false;

    return true;
}
