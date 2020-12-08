#include "../Headers/variable.h"

Variable::Variable(string name): _name(name)
{

}


bool Variable::calculable()
{
    return seekVariable(_name) != -1;
}

float Variable::calculate()
{
    if(calculable())
    {
        int varIndex = seekVariable(_name), valIndex = 0;
        for(int value:_values)
            if(valIndex++ == varIndex)
                return value;
    }

    return 0.0;
}

void Variable::displayN(ostringstream &stream)
{
    stream << _name;
}

void Variable::displayPin(ostringstream &stream)
{
    stream << _name << " ";
}
