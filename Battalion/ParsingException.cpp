#include "ParsingException.hpp"

string ParsingException::what() const
{
    string text;
    text+= "Тип об\'єкта : " + objectType + ". ";
    if(this->badFormat)
    {
        text += "Поганий формат поля : " + property + ".";
    }
    else
    {
        text += "Відсутнє поле : " + property +".";
    }
    return text;
}
ParsingException& ParsingException::setObjectType(const string& objType)
{
    objectType = objType;
    return *this;
}
ParsingException& ParsingException::setProperty(const string& property)
{
    this->property = property;
    return *this;
}
ParsingException& ParsingException::setBadFormat(bool badFormat)
{
    this->badFormat = badFormat;
    return *this;
}

ParsingException& ParsingException::setAdditionInfo(const string& additionInfo)
{
    this->additionInfo = additionInfo;
    return  *this;
}
