#include "../Headers/symboltable.h"

SymbolTable::SymbolTable()
{

}

Variable *SymbolTable::getVariable(const string &name)
{
    if(symbolExists(name))
    {
        list<Variable *>::iterator v;
        for(v = _variables.begin(); v != _variables.end(); v++)
            if((*v) -> getName() == name)
                return *v;
    }
    return (Variable *)NULL;
}

bool SymbolTable::symbolExists(const string &name) const
{
    for(Variable *v:_variables)
        if(v -> getName() == name)
            return true;

    return false;
}

bool SymbolTable::addVariable(Variable *toAdd)
{
    if(!symbolExists(toAdd -> getName()))
        _variables.push_back(toAdd);
    else return false;

    return true;
}

bool SymbolTable::addVariable(const Variable &toAdd)
{
    if(!symbolExists(toAdd.getName()))
        _variables.push_back(new Variable(toAdd));
    else return false;

    return true;
}

bool SymbolTable::editVariable(const Variable &toEdit)
{
    if(symbolExists(toEdit.getName()))
    {
        list<Variable *>::iterator v;
        for(v = _variables.begin(); v != _variables.end(); v++)
            if((*v) -> getName() == toEdit.getName())
                (*v) -> setValue(toEdit.calculate());
        return true;
    }
    return false;
}

bool SymbolTable::setValue(const Variable &toSet)
{
    if(symbolExists(toSet.getName()))
        return editVariable(toSet);

    return addVariable(new Variable(toSet));
}

bool SymbolTable::deleteVariable(const string &name)
{
    if(symbolExists(name))
        for(list<Variable *>::iterator v = _variables.begin(); v != _variables.end(); v++)
            if((*v) -> getName() == name)
            {
                //Deleting contained object
                delete *v;

                //Removing slot
                _variables.erase(v);
                return true;
            }

    return false;
}

bool SymbolTable::isConsistent() const
{
    for(Variable *v:_variables)
        if(v == NULL)
            return false;

    return true;
}

void SymbolTable::displayContent(ostringstream &stream) const
{
    for(Variable *v:_variables)
    {
        if(v != NULL)
            stream << v -> getRepresentation();
        else
            stream << "Reading error";
        stream << endl;
    }
}
