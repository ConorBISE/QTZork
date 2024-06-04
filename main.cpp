#include "qtzork.h"
#include "util/logging.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    LOGGER = new Logger();

    QApplication a(argc, argv);
    game::QTZork w;
    w.show();
    int ret = a.exec();

    delete LOGGER;
    return ret;
}
