#include "mainwindow.h"

#include "Headers/sum.h"
#include "Headers/substraction.h"
#include "Headers/product.h"
#include "Headers/division.h"
#include "Headers/value.h"
#include "Headers/symboltable.h"

#include <QString>

#include <QTextEdit>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextEdit txt;
    ostringstream _stream;

    SymbolTable sym;

    sym.addValue(Variable("A", 6));
    sym.addValue(Variable("B", 4));
    sym.addValue(Variable("C"));

    sym.setValue(Value("A", 8));
    //sym.deleteValue("B");   //<--Try uncommenting this to get the second Sum malfunctionning

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
            sym.getValue("A"),
            new Multiplication(
                new Constante(3),
                sym.getValue("B")
            )
        ),

        //Can't operate this one
        Addition(
            sym.getValue("A"),
            new Multiplication(
                new Constante(3),
                sym.getValue("C")
            )
        )
    };


    sym.displayContent(_stream);
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
