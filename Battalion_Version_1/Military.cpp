#include "Military.hpp"
#include <QChar>
Military::Military():number(0),age(0) { }

Military::Military(unsigned number, const QString& surname, const QString& name, unsigned age,const QString& bloodType,const QString& runk,const vector<QString>& ammunition):
    number(number),
    surname(surname),
    name(name),
    age(age),
    ammunition(ammunition)
{
    setBloodType(bloodType);
    setRunk(runk);
}
Military::Military(const QJsonObject& jsonObj)
{
    try
    {

        Military tmp_military = Military();
        int tmpIntVal = getIntProperty(jsonObj,"number");
        if(tmpIntVal <= 0)
        {
            throw ParsingException("","age",true);
        }
        tmp_military.setNumber(static_cast<unsigned>(tmpIntVal));
        tmp_military.setSurname(getStringProperty(jsonObj,"surname"));
        tmp_military.setName(getStringProperty(jsonObj,"name"));
        tmpIntVal = getIntProperty(jsonObj,"age");
        if(tmpIntVal < 0)
        {
            throw ParsingException("","age",true);
        }
        tmp_military.setAge(static_cast<unsigned>(tmpIntVal));
        tmp_military.setBloodType(getStringProperty(jsonObj,"bloodType"));
        tmp_military.setRunk(getStringProperty(jsonObj,"runk"));
        if(!jsonObj.contains("ammunitions"))
        {
            throw ParsingException("","ammunitions",false);
        }
        if(!jsonObj["ammunitions"].isArray())
        {
            throw ParsingException("","ammunitions",true);
        }
        QJsonArray jsonAmmunitions = jsonObj["ammunitions"].toArray();
        vector<QString> tmp_ammunition;
        for(int i = 0; i < jsonAmmunitions.size();++i)
        {
            if(!jsonAmmunitions[i].isString())
            {
                throw ParsingException("",QString("ammunitions[")  + QString::number(i) + "]",true);
            }
            tmp_ammunition.push_back(jsonAmmunitions[i].toString());
        }

        (*this) = move(tmp_military);
        this->ammunition = move(tmp_ammunition);
    }
    catch(ParsingException& exc)
    {
        exc.setObjectType(typeid(*this).name());
        throw exc;
    }
}


Military& Military::setNumber(unsigned number)
{
    this->number = number;
    return *this;
}
bool Military::isSurnameOrName(const QString& text)
{
    bool wasLetter = false;
    int i = 0;
    while(i<text.size())
    {
        if(text[i].isUpper())
        {
            wasLetter = true;
            ++i;
            break;
        }
        ++i;
    }
    if(!wasLetter)
    {
        return false;
    }
    while(i <  text.size())
    {
       if(!text[i].isLetter())
        {
            return false;
        }
        ++i;
    }
    return true;

}
Military& Military::setSurname(const QString& surname)
{
    this->surname = surname;
    return *this;
}

Military& Military::setName(const QString& name)
{
    this->name = name;
    return *this;
}
Military& Military::setAge(unsigned age)
{
    this->age = age;
    return *this;
}

Military& Military::setRunk(const QString& runk)
{
    this->runk = runk;
    return *this;
}
Military& Military::setBloodType(const QString& bloodType)
{
    const vector<QString>& bloodTypes = LimitedDataLists::Get().getBloodTypes();
    bool exist = false;
    for(const auto& type:bloodTypes)
    {
        if(type == bloodType)
        {
            exist = true;
            break;
        }
    }
    if(!exist)
    {
        throw BadBloodTypeException("No such type");
    }
    this->bloodType = bloodType;
    return *this;
}
QJsonObject Military::toQJsonObject() const
{
    QJsonObject jsonMilitary;
    jsonMilitary.insert("number",QJsonValue(QString::number(number)));
    jsonMilitary.insert("surname",QJsonValue(surname));
    jsonMilitary.insert("name",QJsonValue(name));
    jsonMilitary.insert("age",QJsonValue(QString::number(age)));
    jsonMilitary.insert("bloodType",QJsonValue(bloodType));
    jsonMilitary.insert("runk",QJsonValue(runk));

    QJsonArray jsonAmmunisions;
    for(size_t i = 0; i < ammunition.size();++i)
    {
        jsonAmmunisions.push_back(QJsonValue(ammunition[i]));
    }
    jsonMilitary.insert("ammunitions",jsonAmmunisions);
    return jsonMilitary;
}



