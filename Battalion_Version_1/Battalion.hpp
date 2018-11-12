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
#include <functional>
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
    vector<Military> getMilitaries(function<bool(const Military&)> pred);
private:
    QString name;
    vector<Military> militaries;
};

#endif // BATTALION_HPP
