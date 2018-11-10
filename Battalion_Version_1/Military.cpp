#include "Military.hpp"

Military::Military():number(0),age(0) { }

Military::Military(unsigned number, const string& surname, const string& name, unsigned age,const string& bloodType,const string& runk,const vector<string>& ammunition):
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
        tmp_military.setSurname(getStringProperty(jsonObj,"surname").toStdString());
        tmp_military.setName(getStringProperty(jsonObj,"name").toStdString());
        tmpIntVal = getIntProperty(jsonObj,"age");
        if(tmpIntVal < 0)
        {
            throw ParsingException("","age",true);
        }
        tmp_military.setAge(static_cast<unsigned>(tmpIntVal));
        tmp_military.setBloodType(getStringProperty(jsonObj,"bloodType").toStdString());
        tmp_military.setRunk(getStringProperty(jsonObj,"runk").toStdString());
        if(!jsonObj.contains("ammunitions"))
        {
            throw ParsingException("","ammunitions",false);
        }
        if(!jsonObj["ammunitions"].isArray())
        {
            throw ParsingException("","ammunitions",true);
        }
        QJsonArray jsonAmmunitions = jsonObj["ammunitions"].toArray();
        vector<string> tmp_ammunition;
        for(int i = 0; i < jsonAmmunitions.size();++i)
        {
            if(!jsonAmmunitions[i].isString())
            {
                throw ParsingException("",string("ammunitions[")  + to_string(i) + "]",true);
            }
            tmp_ammunition.push_back(jsonAmmunitions[i].toString().toStdString());
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
Military& Military::setSurname(const string& surname)
{
    this->surname = surname;
    return *this;
}

Military& Military::setName(const string& name)
{
    this->name = name;
    return *this;
}
Military& Military::setAge(unsigned age)
{
    this->age = age;
    return *this;
}

Military& Military::setRunk(const string& runk)
{
    this->runk = runk;
    return *this;
}
Military& Military::setBloodType(const string& bloodType)
{
    const vector<string>& bloodTypes = LimitedDataLists::Get().getBloodTypes();
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
    jsonMilitary.insert("surname",QJsonValue(QString::fromStdString(surname)));
    jsonMilitary.insert("name",QJsonValue(QString::fromStdString(name)));
    jsonMilitary.insert("age",QJsonValue(QString::number(age)));
    jsonMilitary.insert("runk",QJsonValue(QString::fromStdString(runk)));
    QJsonArray jsonAmmunisions;
    for(size_t i = 0; i < ammunition.size();++i)
    {
        jsonAmmunisions.push_back(QJsonValue(QString::fromStdString(ammunition[i])));
    }
    jsonMilitary.insert("ammunusions",jsonAmmunisions);
    return jsonMilitary;
}



