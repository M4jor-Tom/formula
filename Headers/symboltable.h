#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <list>
#include "variable.h"

class SymbolTable
{
private:
    list<Variable *> _variables;
public:
    SymbolTable();

    //Get Variable object from name
    Variable *getVariable(const string &name);

    //Check if a Variable is found with given name
    bool symbolExists(const string &name) const;

    //TABLE EDITORS
    //Adds a Variable in table if no Variable with the same name exists in exists
    bool addVariable(Variable *toAdd);
    bool addVariable(const string name, const float value);
    bool addVariable(const Variable &toAdd);

    //Edits a Variable with the same name than the given variable, to its variable
    bool editVariable(const Variable &toEdit);

    //Choose between addVariable() or editVariable()
    bool setValue(const Variable &toSet);

    //Delete a Variable from list
    bool deleteVariable(const string &name);

    //Checks if every list's slots have a non-null adress
    bool isConsistent() const;

    //Display contained variables
    void displayContent(ostringstream &stream) const;
};

#endif // SYMBOLTABLE_H
