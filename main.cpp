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

    Division sums[] =
    {
        //Operating just values
        Division(
            new Value(6),
            new Product(
                new Value(3),
                new Value(4)
            )
        ),

        //Operating named values
        Division(
            new Value("A", 6),
            new Product(
                new Value(3),
                new Value("B", 4)
            )
        ),

        //Can't operate this one
        Division(
            new Value(6),
            new Product(
                new Value(3),
                new Value("C")
            )
        )
    };

    for(Division sum:sums)
    {
        _stream << "Classic: \t"; sum.displayN(_stream);
        _stream << endl;
        _stream << "R.polish: \t"; sum.displayPin(_stream);
        _stream << endl << "Result: \t" << sum.calculate() << endl << endl;
    }

    //Display result
    txt.setText(_stream.str().c_str());

    txt.show();
    return a.exec();
}
