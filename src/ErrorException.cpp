#include "ErrorException.h"

ErrorException::ErrorException() {}
ErrorException::ErrorException(ErrorException const &rhs) {
    *this = rhs;
}
ErrorException::~ErrorException() {}
ErrorException::ErrorException(std::string error) : error(error) {}
ErrorException & ErrorException::operator=(ErrorException const &rhs)
{
    this->error = rhs.error;
    return *this;
}
const std::string &ErrorException::getError() const {
    return this->error;
}
