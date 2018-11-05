#ifndef PARSINGEXCEPTION_H
#define PARSINGEXCEPTION_H
#include <stdexcept>
#include "BasicFunctionality.hpp"

class ParsingException
{
public:
    ParsingException(const string& objType,const string& property,bool badFormat,const string& additionInfo = ""):objectType(objType),
        property(property),
        badFormat(badFormat),
        additionInfo(additionInfo)
    {
    }

    const string& getObjectType()const { return objectType; }
    ParsingException& setObjectType(const string& objType);

    const string& getProperty() const { return property; }
    ParsingException& setProperty(const string& property);

    bool getBadFormat()const { return badFormat; }
    ParsingException& setBadFormat(bool badFormat);

    const string& getAdditionInfo() const { return additionInfo; }
    ParsingException& setAdditionInfo(const string& additionInfo);

    string what() const;
private:
    string objectType;
    string property;
    bool badFormat;
    string additionInfo;


};

#endif // PARSINGEXCEPTION_H
