#include "../Headers/expression.h"

Expression::Expression()
{

}

void Expression::relayAssignements(list<Assignement *> *assignements)
{
    _assignements = assignements;
}

list<Assignement *> *Expression::getAssignements()
{
    return _assignements;
}

int Expression::seekVariable(string needle)
{
    unsigned int index = 0;
    for(Assignement *_assignement:*_assignements)
        if(_assignement -> getName() == needle)
            return index;
        else
            index++;
    return -1;
}

void Expression::displayVariables(ostringstream &stream)
{
    for(Assignement *_assignement:*_assignements)
        stream << _assignement -> getName() << " = " << _assignement -> getValue() << endl;
}

bool Expression::newVariable(Assignement * assignement)
{
    if(seekVariable(assignement -> getName()) == -1)
    {
        _assignements -> push_back(assignement);
    }
    else
        return false;

    return true;
}

/*bool Expression::newVariable(string name, float value)
{
    if(seekVariable(name) == -1)
    {
        _assignements.push_back(new Assignement(name, value));
    }
    else
        return false;

    return true;
}

bool Expression::setVariable(Assignement *assignement)
{
    int seekResult = seekVariable(assignement -> getName());
    if(seekResult == -1)
    {
        return newVariable(assignement);
    }
    else
    {
        list<Assignement *>::iterator it;
        for(it = _assignements.begin(); it != _assignements.end(); it++)
            if((*it) -> getName() == assignement -> getName())
                (*it) -> setValue(assignement -> getValue());
    }

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
        list<Assignement *>::iterator it;
        for(it = _assignements.begin(); it != _assignements.end(); it++)
            if((*it) -> getName() == name)
                (*it) -> setValue(value);
    }

    return true;
}*/

float Expression::calculer()
{
    return calculate();
}

void Expression::afficher(ostringstream &stream)
{
    displayN(stream);
}

void Expression::afficherNPI(ostringstream &stream)
{
    displayPin(stream);
}
