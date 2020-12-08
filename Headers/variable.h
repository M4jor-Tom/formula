#ifndef VARIABLE_H
#define VARIABLE_H

#include "expression.h"

class Variable: public Expression
{
private:
    string _name;
public:
    Variable(string name);

    bool calculable() override;
    float calculate() override;
    void displayN(ostringstream &stream) override;
    void displayPin(ostringstream &stream) override;
};

#endif // VARIABLE_H
