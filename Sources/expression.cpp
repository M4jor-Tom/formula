#include "../Headers/expression.h"

Expression::Expression()
{

}

float Expression::calculer()
{
    return calculate();
}

void Expression::afficher(ostringstream &stream)
{
    displayN(stream);
}

void Expression::afficherNPI(ostringstream &stream)
{
    displayPin(stream);
}
