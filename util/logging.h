#ifndef LOGGING_H
#define LOGGING_H

//#define JSON_DEBUGGING
#define OBJ_DEBUGGING

#if defined(JSON_DEBUGGING) || defined(OBJ_DEBUGGING)
#include <QDebug>
#endif

class Logger {
public:
    Logger();

    template<class T> void logJson(T t) {
#ifdef JSON_DEBUGGING
        qDebug() << t;
#endif
    };

    template<class T> void logObj(T t) {
#ifdef OBJ_DEBUGGING
        qDebug() << t;
#endif
    };
};

extern Logger *LOGGER;

#endif // LOGGING_H
