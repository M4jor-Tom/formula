#ifndef VARIABLE_H
#define VARIABLE_H

#include "value.h"

class Variable : public Value
{
private:
    string _name;
    bool _set;
public:
    Variable(string name);
    Variable(string name, float value);
    Variable(const Variable &v);

    bool calculable() const override;

    string getFormulaRepresentation() const override;
    string getRepresentation() const override;

    string getName() const;
};

#endif // VARIABLE_H
