#ifndef ASSIGNEMENT_H
#define ASSIGNEMENT_H

#include <sstream>

using namespace std;

class Assignement
{
private:
    string _name;
    float _value;
public:
    Assignement(string name, float value);

    string getName() const;
    float getValue() const;

    bool setValue(float value);
};

#endif // ASSIGNEMENT_H
