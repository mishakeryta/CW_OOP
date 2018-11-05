#include "Battalion.hpp"


const Battalion& Battalion::readFormJson(const string& name)
{
    if(name.length() <= 6  || name.substr(name.find_last_of('.')+1) != "json")
    {
        throw FileException("Погана назва json файлу");
    }
    QFile jsonFile (QString::fromStdString(name));
    if(!jsonFile.open(QIODevice::ReadOnly))//Відкриття файлу з запитаннями і перевірка чи правильно відкрився
    {
        throw FileException("Connot open file");
    }
    QByteArray allFromJsonFile = jsonFile.readAll();
    QJsonDocument jsonDocument = QJsonDocument::fromJson(allFromJsonFile);
    if(jsonDocument.isNull())
    {
        throw ParsingException("Battalion","object",false);
    }
    if(!jsonDocument.isObject())
    {
        throw ParsingException("Battalion","object",true);
    }
    QJsonObject jsonBattalion = jsonDocument.object();
    string tmp_name = getStringProperty(jsonBattalion,"name").toStdString();

    if(!jsonBattalion.contains("militaries"))
    {
        throw ParsingException("Battalion","militaries",false);
    }
    if(!jsonBattalion["militaries"].isArray())
    {
        throw ParsingException("Battalion","militaries",true);
    }
    QJsonArray jsonMilitaries = jsonBattalion[QString("militaries")].toArray();
    vector<Military> tmp_militaries;
    for(int i = 0; i < jsonMilitaries.size();++i)
    {
        if(jsonMilitaries[i].isObject())
        {
            try
            {
                tmp_militaries.emplace_back(jsonMilitaries[i].toObject());
            }
            catch(ParsingException exc)
            {
                throw ParsingException(typeid(*this).name(),
                                 "militaries["+to_string(i)+"]."+exc.getProperty(),
                                 exc.getBadFormat());
            }
        }
        else
        {
            throw ParsingException("Battalion",string("militaries[") + to_string(i) + "]",true);
        }
    }
    this->militaries = tmp_militaries;
    this->name = tmp_name;
    return *this;
}
