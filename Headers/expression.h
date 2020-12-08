#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <sstream>

using namespace std;

class Expression
{
public:
    Expression();

    virtual void displayN(ostringstream &stream) = 0;
    virtual void displayPin(ostringstream &stream) = 0;
    virtual bool calculable() = 0;
    virtual float calculate() = 0;
};

#endif // EXPRESSION_H
