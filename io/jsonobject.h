#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include "../util/hashmap.h"

#include <string>
#include <vector>
#include <istream>

namespace io {

class JsonObject
{
public:
    JsonObject();
    JsonObject(JsonObject& o);
    ~JsonObject();

    enum Type {NUMBER, STRING, LIST, OBJECT, BOOLEAN, JSON_NULL};

    void parseFromString(std::string s);

    Type getType() const;
    int getValNum() const;
    std::string getValString() const;
    std::vector<JsonObject*>* getValList() const;
    HashMap<std::string, JsonObject*>* getValObject() const;
    bool getValBool() const;

private:
    union {
        int valNum;
        std::string* valString;
        std::vector<JsonObject*>* valList;
        HashMap<std::string, JsonObject*> *valObject;
        bool valBool;
    };

    Type type;
};

QDebug operator<<(QDebug debug, const JsonObject &o);
QDebug operator<<(QDebug debug, const JsonObject *&o);

std::istream& operator>>(std::istream &in, JsonObject &o);

}

#endif // JSONOBJECT_H
