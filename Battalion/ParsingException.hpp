#ifndef PARSINGEXCEPTION_H
#define PARSINGEXCEPTION_H
#include <stdexcept>
using namespace std;
class ParsingException:public logic_error
{
public:
    using std::logic_error::logic_error;
};

#endif // PARSINGEXCEPTION_H
