#ifndef ERROR_EXCEPTION
#define ERROR_EXCEPTION
#include <exception>
#include <string>

class ErrorException : public std::exception{
public:
    ErrorException();
    ~ErrorException();
    ErrorException(std::string);
    const std::string &getError() const;
    ErrorException & operator=(ErrorException const &rhs);
    ErrorException(ErrorException const &rhs);

private:
    std::string error;
};

#endif 