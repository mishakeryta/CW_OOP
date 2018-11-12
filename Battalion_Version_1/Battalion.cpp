#include "Battalion.hpp"
#include <QDir>
#include <QFileInfo>
const Battalion& Battalion::readFormJson(const QString& name)
{
    QString tmp = QFileInfo(name).suffix();
    if(name.length() <= 6  || QFileInfo(name).suffix() != QString("json"))
    {
        throw FileException("Погана назва json файлу");
    }

    QFile jsonFile(name);
    if(!jsonFile.open(QIODevice::ReadOnly))//Відкриття файлу з запитаннями і перевірка чи правильно відкрився
    {
        throw FileException("Не можливо відкрити файл, можливо його просто не існує.");
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
    QString tmp_name = getStringProperty(jsonBattalion,"name");

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
                throw ParsingException("Battalion",
                                 "militaries["+QString::number(i)+"]."+exc.getProperty(),
                                 exc.getBadFormat());
            }
        }
        else
        {
            throw ParsingException("Battalion",QString("militaries[") + QString::number(i) + "]",true);
        }
    }
    this->militaries = tmp_militaries;
    this->name = tmp_name;
    jsonFile.close();
    return *this;
}
QJsonObject Battalion::toJsonOnject() const
{
    QJsonObject jsonBattalion;
    jsonBattalion.insert("name",this->name);
    QJsonArray jsonMilitaries;
    for(size_t i = 0; i < militaries.size();++i)
    {
        jsonMilitaries.push_back(militaries[i].toQJsonObject());
    }
    jsonBattalion.insert("militaries",jsonMilitaries);
    return jsonBattalion;
}

Military& Battalion::getMilitary(size_t index)
{
    return militaries.at(index);
}
vector<Military>& Battalion::getMilitaries()
{
    return militaries;
}

vector<Military> Battalion::getMilitaries(function<bool(const Military&)> pred)
{
    vector<Military> suitMilitaries;
    for(auto& military:militaries)
    {
        if(pred(military))
        {
            suitMilitaries.push_back(military);
        }
    }
    return suitMilitaries;
}
