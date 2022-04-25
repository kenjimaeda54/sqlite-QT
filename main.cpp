#include "sqlit.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SQlit w;
    w.show();
    return a.exec();
}
