#ifndef JSONPARSEEXCEPTION_H
#define JSONPARSEEXCEPTION_H

#include <cstring>
#include <exception>
#include <string>

namespace io {


class JsonParseException : public std::exception
{
public:
    JsonParseException(std::string value);
    const char *what() const noexcept override;

private:
    std::string value;
};

}

#endif // JSONPARSEEXCEPTION_H
