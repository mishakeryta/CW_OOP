#ifndef BADBLOODTYPEEXCEPTION_HPP
#define BADBLOODTYPEEXCEPTION_HPP
#include <stdexcept>
using namespace std;

class BadBloodTypeException:public logic_error
{
public:
   using std::logic_error::logic_error;
};

#endif // BADBLOODTYPEEXCEPTION_HPP
