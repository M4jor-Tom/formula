#ifndef VALUE_H
#define VALUE_H

#define VALUE 0
#define NAME 1
#define BOTH 2

#include "expression.h"

class Value: public Expression
{
private:
    float _value;
    string _name;
    unsigned short int interpretation;
public:
    //Constructors
    Value(float value);
    Value(string name);
    Value(string name, float value);

    //Methods
    bool calculable() override;
    float calculate() override;
    bool setValue(float value);
    string getRepresentation();
    void displayN(ostringstream &stream) override;
    void displayPin(ostringstream &stream) override;
};

#endif // VALUE_H
