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
        throw ParsingException("Bad json name\n");
    }
    if (name.substr(name.find_last_of('.'+1)) == "json")
    {
       throw ParsingException("Bad json name\n");
    }
    QFile jsonFile (QString::fromStdString(name));
    if(!jsonFile.open(QIODevice::ReadOnly)) {//Відкриття файлу з запитаннями і перевірка чи правильно відкрився
                throw NoFileException("Connot open file");
    }
    QByteArray allFromJsonFile = jsonFile.readAll();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(allFromJsonFile);
    if(jsonDocument.isNull()) exit(-1);
    if(jsonDocument.isObject()) {
        throw ParsingException("No Battalion onject in file "+ name);
    }
    QJsonObject jsonBattalion = jsonDocument.object();
    this->name = jsonBattalion[QString("name")].toString().toStdString();
    QJsonArray jsonMilitaries = jsonBattalion[QString("militaries")].toArray();
    vector<Military> tmp_militaries;
    for(int i = 0; i < jsonMilitaries.size();++i)
    {
        if(jsonMilitaries[i].isObject())
        {
            tmp_militaries.push_back(jsonMilitaries[i].toObject());
        }
        else
        {
            throw(ParsingException(string("Military wiht index ") + to_string(i) + " is not an object\n"));
        }
    }
    militaries = tmp_militaries;
}
