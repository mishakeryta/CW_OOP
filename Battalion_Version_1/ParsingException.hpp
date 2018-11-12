#ifndef PARSINGEXCEPTION_H
#define PARSINGEXCEPTION_H
#include <stdexcept>
#include "BasicFunctionality.hpp"

class ParsingException
{
public:
    ParsingException(const QString& objType,const QString& property,bool badFormat,const QString& additionInfo = ""):objectType(objType),
        property(property),
        badFormat(badFormat),
        additionInfo(additionInfo)
    {
    }

    const QString& getObjectType()const { return objectType; }
    ParsingException& setObjectType(const QString& objType);

    const QString& getProperty() const { return property; }
    ParsingException& setProperty(const QString& property);

    bool getBadFormat()const { return badFormat; }
    ParsingException& setBadFormat(bool badFormat);

    const QString& getAdditionInfo() const { return additionInfo; }
    ParsingException& setAdditionInfo(const QString& additionInfo);

    QString what() const;
private:
    QString objectType;
    QString property;
    bool badFormat;
    QString additionInfo;


};

#endif // PARSINGEXCEPTION_H
