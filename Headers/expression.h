#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <sstream>

using namespace std;

class Expression
{
public:
    Expression();
    virtual ~Expression();

    virtual void displayN(ostringstream &stream) const = 0;
    virtual void displayPin(ostringstream &stream) const = 0;
    virtual bool calculable() const = 0;
    virtual float calculate() const = 0;

    //French translation
    float calculer() const;
    void afficher(ostringstream &stream) const;
    void afficherNPI(ostringstream &stream) const;
};

#endif // EXPRESSION_H
