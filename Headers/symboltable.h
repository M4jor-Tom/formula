#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <list>
#include "value.h"

class SymbolTable
{
private:
    list<Value *> _values;
public:
    SymbolTable();

    //Get Value object from name
    Value *getValue(const string &name);

    //Check if a value is found with given name
    bool symbolExists(const string &name) const;

    //TABLE EDITORS
    //Adds a Value in table if no Value with the same name exists in exists
    bool addValue(Value *toAdd);
    bool addValue(const Value &toAdd);

    //Edits a Value with the same name than the given Value, to its value
    bool editValue(const Value &toEdit);

    //Choose between addValue() or editValue()
    bool setValue(const Value &toSet);

    //Delete a Value from list
    bool deleteValue(const string &name);

    //Checks if every list's slots have a non-null adress
    bool isConsistent() const;

    //Display contained variables
    void displayContent(ostringstream &stream) const;
};

#endif // SYMBOLTABLE_H
