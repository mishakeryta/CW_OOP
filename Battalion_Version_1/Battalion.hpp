#ifndef BATTALION_HPP
#define BATTALION_HPP
#include "BasicFunctionality.hpp"
#include "Military.hpp"
#include "FileException.hpp"
#include "ParsingException.hpp"
#include <stdexcept>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QByteArray>
#include <QJsonValue>
using namespace std;
class Battalion
{
public:
    Battalion(){}
    const Battalion& readFormJson(const QString& name);
    QJsonObject toJsonOnject() const;
    const QString& getName() const{return  name; }
    Military& getMilitary(size_t index);
    vector<Military>& getMilitaries();
private:
    QString name;
    vector<Military> militaries;
};

#endif // BATTALION_HPP
