#include "../Headers/symboltable.h"

SymbolTable::SymbolTable()
{

}

Value *SymbolTable::getValue(const string &name)
{
    if(symbolExists(name))
    {
        list<Value *>::iterator v;
        for(v = _values.begin(); v != _values.end(); v++)
            if((*v) -> getName() == name)
                return *v;
    }
    return (Value *)NULL;
}

bool SymbolTable::symbolExists(const string &name) const
{
    for(Value *v:_values)
        if(v -> getName() == name)
            return true;

    return false;
}

bool SymbolTable::addValue(Value *toAdd)
{
    if(!symbolExists(toAdd -> getName()))
        _values.push_back(toAdd);
    else return false;

    return true;
}

bool SymbolTable::addValue(const Value &toAdd)
{
    if(!symbolExists(toAdd.getName()))
        _values.push_back(new Value(toAdd));
    else return false;

    return true;
}

bool SymbolTable::editValue(const Value &toEdit)
{
    if(symbolExists(toEdit.getName()))
    {
        list<Value *>::iterator v;
        for(v = _values.begin(); v != _values.end(); v++)
            if((*v) -> getName() == toEdit.getName())
                (*v) -> setValue(toEdit.calculate());
        return true;
    }
    return false;
}

bool SymbolTable::setValue(const Value &toSet)
{
    if(symbolExists(toSet.getName()))
        return editValue(toSet);

    return addValue(new Value(toSet));
}

bool SymbolTable::deleteValue(const string &name)
{
    if(symbolExists(name))
        for(list<Value *>::iterator v = _values.begin(); v != _values.end(); v++)
            if((*v) -> getName() == name)
            {
                //Deleting contained object
                delete *v;

                //Removing slot
                _values.erase(v);
                return true;
            }

    return false;
}

bool SymbolTable::isConsistent() const
{
    for(Value *v:_values)
        if(v == NULL)
            return false;

    return true;
}

void SymbolTable::displayContent(ostringstream &stream) const
{
    for(Value *v:_values)
    {
        if(v != NULL)
            v -> displayN(stream);
        else
            stream << "Reading error";
        stream << endl;
    }
}
