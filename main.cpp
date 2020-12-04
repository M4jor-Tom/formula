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

    //Operating
    Sum s(new Value(6), new Product(new Value(3), new Value(4)));

    s.displayN(_stream);

    //Display result
    txt.setText(_stream.str().c_str());

    txt.show();
    return a.exec();
}
