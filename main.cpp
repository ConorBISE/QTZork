#include "qtzork.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTZork w;
    w.show();
    return a.exec();
}
