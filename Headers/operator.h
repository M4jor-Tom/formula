#ifndef OPERATOR_H
#define OPERATOR_H


#include <string>
#include "expression.h"

using namespace std;

class Operator: public Expression
{
protected:
    Expression *_lOpPt, *_rOpPt;
    string _operator;
public:
    Operator();

    virtual bool calculable() const override;
    bool operable() const;
    void displayN(ostringstream &stream) const override;
    void displayPin(ostringstream &stream) const override;
};


//French translation
typedef Operator Operateur;

#endif // OPERATOR_H
