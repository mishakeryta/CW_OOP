#include "Battalion.hpp"
#include <stdexcept>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QByteArray>


Battalion Battalion::readFormJson(const string& name)
{
    if(name.length() <= 6)
    {
        throw logic_error("Bad json name\n");
    }
    if (name.substr(name.find_last_of('.'+1)) == "json")
    {
       throw logic_error("Bad json name\n");
    }
    QFile jsonFile (QString::fromStdString(name));
    QByteArray allFromJsonFile = jsonFile.readAll();






}
