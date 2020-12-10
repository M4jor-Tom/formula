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
    unsigned short int _interpretation;
public:
    //Constructors
    Value(float value);
    Value(string name);
    Value(string name, float value);
    Value(const Value &v);

    //--Methods
    //Testers
    bool calculable() const override;

    //Setters
    bool setValue(float value);

    //Getters
    float calculate() const override;
    string getRepresentation() const;
    string getName() const;

    //Displayers
    void displayN(ostringstream &stream) const override;
    void displayPin(ostringstream &stream) const override;
};

//Alias (English + French)
typedef Value Variable;

//French translation
typedef Value Constante;

#endif // VALUE_H
