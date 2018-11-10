#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>

class Converter
{
public:
    template<class ForwardIter, class ConvertType>
    static std::string toString(ForwardIter begin, ForwardIter end,ConvertType convert);
};
template<class ForwardIter, class ConvertType>
std::string Converter::toString(ForwardIter begin, ForwardIter end, ConvertType convert)
{
    std::string result;
    while(begin!= end)
    {
        result+= convert(*begin);
        ++begin;
    }
    return result;
}


#endif // CONVERTER_HPP
