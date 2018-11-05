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
    const Battalion& readFormJson(const string& name);
    QJsonObject toJsonOnject() const;
    const string& getName() const;
    Military& getMilitary(size_t index);
    vector<Military>& getMilitaries();
private:
    string name;
    vector<Military> militaries;
};

#endif // BATTALION_HPP