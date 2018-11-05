#include "JsonParsingAddition.hpp"

QString getStringProperty(const QJsonObject& jsonObj,const string& property)
{
    QString key_property = QString::fromStdString(property);

    if(jsonObj.find(key_property) == jsonObj.constEnd())
    {
        throw ParsingException("",property,false);
    }
    if(!jsonObj[key_property].isString())
    {
        throw ParsingException("",property,true);
    }
    return jsonObj[key_property].toString();
}
int getIntProperty(const QJsonObject& jsonObj,const string& property)
{
    bool successfulIntConvert = true;
    int tmpIntNumber = getStringProperty(jsonObj,property).toInt(&successfulIntConvert);
    if(!successfulIntConvert)
    {
        throw ParsingException("",property,true);
    }
    return tmpIntNumber;
}
