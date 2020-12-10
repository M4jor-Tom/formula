#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "assignement.h"

#include <sstream>
#include <list>

using namespace std;

class Expression
{
protected:
    list<Assignement *> _assignements;
public:
    Expression();

    void relayAssignements(const list<Assignement *> &assignements);
    int seekVariable(string needle);
    bool newVariable(Assignement *assignement);
    /*bool newVariable(string name, float value);
    bool setVariable(Assignement *assignement);
    bool setVariable(string name, float value);*/
    virtual void displayN(ostringstream &stream) = 0;
    virtual void displayPin(ostringstream &stream) = 0;
    virtual bool calculable() = 0;
    virtual float calculate() = 0;

    //French translation
    float calculer();
    void afficher(ostringstream &stream);
    void afficherNPI(ostringstream &stream);
};

#endif // EXPRESSION_H
