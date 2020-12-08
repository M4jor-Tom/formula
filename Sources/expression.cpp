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

bool Expression::setVariable(string name, float value)
{
    int seekResult = seekVariable(name);
    if(seekResult == -1)
    {
        return newVariable(name, value);
    }
    else
    {
        int count;
        list<float>::iterator it;
        for(count = 0, it = _values.begin(); count < _values.size(); count++, it++)
            if(count == seekResult)
                *it = value;
    }

    return true;
}
