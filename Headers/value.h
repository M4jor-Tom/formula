#ifndef VALUE_H
#define VALUE_H

#include "expression.h"

class Value: public Expression
{
protected:
    float _value;
public:
    //Constructor
    Value(float value);

    //--Methods
    //Testers
    virtual bool calculable() const override;

    //Setters
    bool setValue(float value);

    //Getters
    float calculate() const override;
    virtual string getFormulaRepresentation() const;
    virtual string getRepresentation() const;

    //Displayers
    void displayN(ostringstream &stream) const override;
    void displayPin(ostringstream &stream) const override;
};

//French translation
typedef Value Constante;

#endif // VALUE_H
