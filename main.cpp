#include "mainwindow.h"

#include "Headers/sum.h"
#include "Headers/substraction.h"
#include "Headers/product.h"
#include "Headers/division.h"
#include "Headers/value.h"

#include <QString>

#include <QTextEdit>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextEdit txt;
    ostringstream _stream;

    Variable A("A", 6), B("B", 4), C("C");

    Addition sums[] =
    {
        //Operating just values
        Addition(
            new Constante(8),
            new Multiplication(
                new Constante(3),
                new Constante(4)
            )
        ),

        //Operating named values
        Addition(
            &A,
            new Multiplication(
                new Constante(3),
                &B
            )
        ),

        //Can't operate this one
        Addition(
            &A,
            new Multiplication(
                new Constante(3),
                &C
            )
        )
    };

    A.afficher(_stream); _stream << endl;
    B.afficher(_stream); _stream << endl;
    C.afficher(_stream); _stream << endl;
    _stream << endl;
    for(Addition sum:sums)
    {
        _stream << "Classic: \t"; sum.afficher(_stream);
        _stream << endl << "R.polish: \t"; sum.afficherNPI(_stream);
        _stream << endl << "Calculable: \t" << sum.calculable();
        _stream << endl << "Result: \t" << sum.calculer() << endl << endl;
    }

    //Display result
    txt.setText(_stream.str().c_str());

    txt.show();
    return a.exec();
}
