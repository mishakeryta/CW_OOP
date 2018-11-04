#ifndef BATTALION_HPP
#define BATTALION_HPP
#include "BasicFunctionality.hpp"
#include "Military.hpp"
#include "NoFileException.hpp"
#include "ParsingException.hpp"
using namespace std;
class Battalion
{
public:
    Battalion(){}
    Battalion readFormJson(const string& name);
private:
    string name;
    vector<Military> militaries;
};

#endif // BATTALION_HPP
