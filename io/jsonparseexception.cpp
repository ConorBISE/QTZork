#include "jsonparseexception.h"

namespace io {

JsonParseException::JsonParseException(std::string value) : value(value) {};

const char *JsonParseException::what() const noexcept {
    std::string val = "Invalid JSON value encountered during parsing: " + value;
    char* valCStr = new char[val.size() + 1];
    strncpy(valCStr, val.c_str(), val.size());
    return valCStr;
}

}
