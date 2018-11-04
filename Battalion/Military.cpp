#include "Military.hpp"


Military::Military(unsigned number, const string& surname, const string& name, unsigned age,unsigned bloodType,string runk,const vector<string>& ammunition):
    number(number),
    surname(surname),
    name(name),
    age(age)
{
    setBloodType(bloodType);


}
Military::Military(const QJsonObject& jsonObj)
{
    const vector<string>& properties = LimitedDataLists::LimitedDataListsSingletone().getMilitaryProperties();
    for(const auto& property:properties)
    {
        QString key_property = QString::fromStdString(property);
        if(jsonObj.find(QString::fromStdString(property)) == jsonObj.constEnd())
        {
            throw ParsingException(string("Property ") + property + " absent in json\n");
        }
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
Military& Military::setBloodType(unsigned bloodType)
{
    if(bloodType==0 || bloodType > 4) throw BadBloodTypeException("");
    this->bloodType = bloodType;
    return *this;
}



