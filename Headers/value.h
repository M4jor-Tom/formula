#ifndef VALUE_H
#define VALUE_H

#include "expression.h"

class Value: public Expression
{
private:
    float _value;
public:
    Value(float value);
    float calculate() override;
    void displayN(ostringstream &stream) override;
    void displayPin(ostringstream &stream) override;
};

#endif // VALUE_H
