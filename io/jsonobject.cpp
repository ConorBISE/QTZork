#include "jsonobject.h"

#include "jsonparseexception.h"
#include "../util/logging.h"

#include <QDebug>
#include <utility>
#include <sstream>

namespace io {

JsonObject::JsonObject() {}

std::pair<std::string, std::string> takeN(int n, std::string s) {
    std::string first = s.substr(0, n);
    std::string rest = s.substr(n);
    return std::make_pair(first, rest);
}

std::pair<std::string, std::string> takeNDiscard(int n, std::string s) {
    std::string first = s.substr(0, n);
    std::string rest = s.substr(n + 1);
    return std::make_pair(first, rest);
}

std::pair<std::string, std::string> takeUntilDiscard(std::string key, std::string s) {
    int idx = s.find_first_of(key);
    return takeNDiscard(idx, s);
}

std::string trimLeft(std::string s) {
    int n = s.find_first_not_of(" \t\n\r\f\v");
    return s.substr(n);
}

std::string trimRight(std::string s) {
    int n = s.find_last_not_of(" \t\n\r\f\v");
    return s.substr(0, n + 1);
}

std::string trim(std::string s) {
    if (s.find_last_not_of(" \t\n\r\f\v") == std::string::npos)
        return "";

    return trimLeft(trimRight(s));
}

std::pair<std::string, std::string> takeUntilNextBalancedComma(std::string s) {
    int curlyBracketCount = 0;
    int squareBracketCount = 0;
    int i = 0;

    for (auto &c : s) {
        if (c == '{')
            curlyBracketCount++;

        if (c == '}')
            curlyBracketCount--;

        if (c == '[')
            squareBracketCount++;

        if (c == ']')
            squareBracketCount--;

        if (c == ',' && curlyBracketCount == 0 && squareBracketCount == 0)
            return takeNDiscard(i, s);

        i++;
    }

    return takeN(i, s);
}

void JsonObject::parseFromString(std::string s) {
    auto [first, rest] = takeN(1, s);

    if (first == "{") {
        LOGGER->logJson("Parsing Object");
        type = Type::OBJECT;

        std::string working = trimLeft(rest);
        bool foundLastKey = false;
        HashMap<std::string, JsonObject*> *map = new HashMap<std::string, JsonObject*>();

        if (working.find("\"") == std::string::npos) {
            // Empty object. Bail out early.
            foundLastKey = true;
        }

        while (!foundLastKey) {
            working = takeUntilDiscard("\"", working).second;
            auto [key, rest] = takeUntilDiscard("\"", working);

            working = takeUntilDiscard(":", working).second;

            auto valueAndRest = takeUntilNextBalancedComma(working);

            std::string valueString = valueAndRest.first;
            working = valueAndRest.second;

            valueString = trim(valueString);
            working = trim(working);

            foundLastKey = working.size() == 0;

            // If this is the last key,
            // trim the trailing closing curly bracket
            if (foundLastKey)
                valueString = valueString.substr(0, valueString.size() - 1);

            JsonObject *val = new JsonObject;
            val->parseFromString(valueString);

            map->put(key, val);
        }

        valObject = map;

    } else if (first == "[") {
        LOGGER->logJson("Parsing List");
        type = Type::LIST;

        std::string working = trimLeft(rest);
        bool foundLastValue = false;
        std::vector<JsonObject*> *list = new std::vector<JsonObject*>;

        if (working.find(",") == std::string::npos) {
            // Empty object. Bail out early.
            foundLastValue = true;
        }

        while (!foundLastValue) {
            auto valueAndRest = takeUntilNextBalancedComma(working);

            std::string valueString = valueAndRest.first;
            working = valueAndRest.second;

            valueString = trim(valueString);
            working = trim(working);

            foundLastValue = working.size() == 0;

            // If this is the last value,
            // trim the trailing closing square bracket
            if (foundLastValue)
                valueString = valueString.substr(0, valueString.size() - 1);

            JsonObject *val = new JsonObject;
            val->parseFromString(valueString);

            list->push_back(val);
        }

        valList = list;

    } else if (first == "\"") {
        LOGGER->logJson("Parsing String");
        type = Type::STRING;
        valString = new std::string(rest.substr(0, rest.length() - 1));

    } else if (s == "null") {
        LOGGER->logJson("Parsing Null");
        type = Type::JSON_NULL;

    } else if (s == "true") {
        LOGGER->logJson("Parsing Boolean");
        type = Type::BOOLEAN;
        valBool = true;

    } else if (s == "false") {
        LOGGER->logJson("Parsing Boolean");
        type = Type::BOOLEAN;
        valBool = false;

    } else if (!s.empty() && std::all_of(s.begin(), s.end(), ::isdigit)) {
        LOGGER->logJson("Parsing Number");
        type = Type::NUMBER;
        valNum = std::stoi(s);

    } else {
        // Invalid JSON value - thow an exception.
        throw JsonParseException(s);
    }
}

JsonObject::JsonObject(JsonObject& o) {
    o.type = type;

    switch (type) {
    case NUMBER:
        o.valNum = valNum;
        break;

    case STRING:
        o.valString = new std::string(*valString);
        break;

    case BOOLEAN:
        o.valBool = valBool;

    case JSON_NULL:
        break;

    case LIST:
        o.valList = new std::vector(*valList);
        break;

    case OBJECT:
        o.valObject = new HashMap<std::string, JsonObject*>(*valObject);
        break;
    }
};

JsonObject::~JsonObject() {
    switch (type) {
    case NUMBER:
    case BOOLEAN:
    case JSON_NULL:
        break;

    case STRING:
        delete valString;
        break;

    case LIST:
        delete valList;
        break;

    case OBJECT:
        delete valObject;
        break;
    }
};

JsonObject::Type JsonObject::getType() const
{
    return type;
}

int JsonObject::getValNum() const
{
    return valNum;
}

std::string JsonObject::getValString() const
{
    return *valString;
}

std::vector<JsonObject*>* JsonObject::getValList() const {
    return valList;
};

HashMap<std::string, JsonObject*>* JsonObject::getValObject() const {
    return valObject;
}

bool JsonObject::getValBool() const {
    return valBool;
}

QDebug operator<<(QDebug debug, const JsonObject &o) {
    switch (o.getType()) {
    case JsonObject::LIST:
        debug << *o.getValList();
        break;

    case JsonObject::OBJECT:
        debug << *o.getValObject();
        break;

    case JsonObject::STRING:
        debug << o.getValString();
        break;

    case JsonObject::JSON_NULL:
        debug << "null";
        break;

    case JsonObject::BOOLEAN:
        debug << o.getValBool();
        break;

    case JsonObject::NUMBER:
        debug << o.getValNum();
        break;

    }

    return debug;
}

QDebug operator<<(QDebug debug, const JsonObject *&o) {
    debug << *o;
    return debug;
}

std::istream& operator>>(std::istream &in, JsonObject &o) {
    std::string s;
    std::ostringstream os;
    in >> os.rdbuf();
    s = os.str();

    o.parseFromString(s);

    return in;
}

}
