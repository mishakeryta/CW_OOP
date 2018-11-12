#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <QString>
class Converter
{
public:
    template<class ForwardIter, class ConvertType>
    static QString toString(ForwardIter begin, ForwardIter end,ConvertType convert);
};
template<class ForwardIter, class ConvertType>
QString Converter::toString(ForwardIter begin, ForwardIter end, ConvertType convert)
{
    QString result;
    while(begin!= end)
    {
        result+= convert(*begin);
        ++begin;
    }
    return result;
}


#endif // CONVERTER_HPP
