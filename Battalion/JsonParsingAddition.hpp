#ifndef JSONPARSINGADDITION_HPP
#define JSONPARSINGADDITION_HPP
#include "BasicFunctionality.hpp"
#include "ParsingException.hpp"
#include <QString>
#include <QJsonObject>

QString getStringProperty(const QJsonObject& jsonObj,const string& property);
int getIntProperty(const QJsonObject& jsonObj, const string& property);

#endif // JSONPARSINGADDITION_HPP