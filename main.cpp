#include "mainwindow.h"

#include "Headers/sum.h"
#include "Headers/substraction.h"
#include "Headers/product.h"
#include "Headers/division.h"
#include "Headers/value.h"
#include "Headers/variable.h"

#include <QString>

#include <QTextEdit>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextEdit txt;
    ostringstream _stream;

    //Operating
    Addition sums[]
    {
        //Normal sum, done normally
        Addition(
            new Variable("A"),
            new Multiplication(
                new Variable("B"),
                new Variable("A")
            )
        ),

        //Same as up there, because variables are shared between sums due to constructor
        Addition(
            sums[0].getAssignements(),
            new Constante(5),
            new Variable("X")
        ),

        //Will cause null result and 'calculacble()' returning 'false' because "Y" is never set
        Addition(
            sums[0].getAssignements(),
            new Constante(8),
            new Variable("Y")
        )
    };

    //Assigning values to Variables and Variables to Expressions
    Assignement A("A", 5), B("B", 10), X("X", 2);
    sums[0].newVariable(&A);    //<--Used to calculate
    sums[0].newVariable(&B);    //<--Used to calculate
    sums[0].newVariable(&X);    //<--Used to calculate
    /*sums[0].newVariable("A", 3);    //<--Ignored because already exists

    sums[0].setVariable("B", 5);    //<--Ignored because overwritten
    sums[0].setVariable(&B);    //<--Overwriting*/

    A.setValue(12);  //<--Updates A's value in every Expression

    //Preparing results
    for(Addition sum:sums)
    {
        //Display of results
        _stream << "Classic:\t"; sum.afficher(_stream);
        _stream << endl;
        _stream << "R.Polish:\t"; sum.afficherNPI(_stream);
        _stream << endl << "Calculable:\t" << sum.calculable() << endl;
        _stream << "Result:\t" << sum.calculer() << endl << endl;
    }

    //Display result
    txt.setText(_stream.str().c_str());

    txt.show();
    return a.exec();
}
