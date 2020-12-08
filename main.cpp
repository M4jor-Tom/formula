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
    Sum sums[]
    {
        //Normal sum, done normally
        Sum(
            new Variable("A"),
            new Product(
                new Value(3),
                new Variable("A")
            )
        ),

        //Will cause null result and 'calculacble()' returning 'false' because "X" is never set
        Sum(
            new Value(5),
            new Variable("X")
        ),

        //Will cause error because missing formula
        Sum()
    };

    sums[0].newVariable("A", 5);    //<--Used to calculate
    sums[0].newVariable("A", 3);    //<--Ignored because already exists

    for(Sum sum:sums)
    {
        //Display of results
        _stream << "Classic:\t"; sum.displayN(_stream);
        _stream << endl;
        _stream << "R.Polish:\t"; sum.displayPin(_stream);
        _stream << endl << "Calculable:\t" << sum.calculable() << endl;
        _stream << "Result:\t" << sum.calculate() << endl << endl;
    }

    //Display result
    txt.setText(_stream.str().c_str());

    txt.show();
    return a.exec();
}
