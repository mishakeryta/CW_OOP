#ifndef NOFILEEXCEPTION_HPP
#define NOFILEEXCEPTION_HPP
#include <stdexcept>
using namespace std;
class NoFileException:public logic_error
{
public:
    using std::logic_error::logic_error;
};

#endif // NOFILEEXCEPTION_HPP
