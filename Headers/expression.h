#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <sstream>
#include <list>

using namespace std;

class Expression
{
protected:
    list<string> _names;
    list<float> _values;
public:
    Expression();

    void relayAssignements(const list<string> &names, const list<float> &values);
    int seekVariable(string needle);
    bool newVariable(string name, float value);
    virtual void displayN(ostringstream &stream) = 0;
    virtual void displayPin(ostringstream &stream) = 0;
    virtual bool calculable() = 0;
    virtual float calculate() = 0;
};

#endif // EXPRESSION_H
