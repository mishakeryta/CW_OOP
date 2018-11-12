#include "ParsingException.hpp"

QString ParsingException::what() const
{
    QString text;
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
ParsingException& ParsingException::setObjectType(const QString& objType)
{
    objectType = objType;
    return *this;
}
ParsingException& ParsingException::setProperty(const QString& property)
{
    this->property = property;
    return *this;
}
ParsingException& ParsingException::setBadFormat(bool badFormat)
{
    this->badFormat = badFormat;
    return *this;
}

ParsingException& ParsingException::setAdditionInfo(const QString& additionInfo)
{
    this->additionInfo = additionInfo;
    return  *this;
}
