#include "../Headers/expression.h"

Expression::Expression()
{

}

Expression::~Expression()
{

}

float Expression::calculer() const
{
    return calculate();
}

void Expression::afficher(ostringstream &stream) const
{
    displayN(stream);
}

void Expression::afficherNPI(ostringstream &stream) const
{
    displayPin(stream);
}
