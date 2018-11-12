#ifndef MILITARY_HPP
#define MILITARY_HPP
#include <string>
#include <vector>
#include <QString>

#include "ParsingException.hpp"
#include "BadBloodTypeException.hpp"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include "LimitedDataLists.hpp"
#include "JsonParsingAddition.hpp"


using namespace std;

class Military
{
public:
//конструктори
    Military();
    Military(unsigned number, const QString& surname, const QString& name, unsigned age,const QString& bloodType,const QString& runk,const vector<QString>& ammunition);
    Military(const QJsonObject& jsonObj);

//властивості
    Military& setNumber(unsigned number);
    unsigned getNumber() const { return this->number;  }

    static bool isSurnameOrName(const QString& text);
    Military& setSurname(const QString& surname);
    QString getSurname() const{ return surname;  }


    Military& setName(const QString& name);
    QString getName() const { return name;  }

    Military&  setAge(unsigned age);
    unsigned getAge() const {return age;  }

    Military& setBloodType(const QString& bloodType);
    QString getBloodType()  const {return  bloodType;  }

    Military& setRunk(const QString& runk);
    QString getRunk() const{return runk; }

    Military& setAmmunition(const vector<QString>& ammunition);
    vector<QString>& getAmmunition()  {return ammunition;  }
    const vector<QString>& getAmmunition()const {return ammunition; }
    QJsonObject toQJsonObject() const;
private:

    unsigned number;
    QString surname;
    QString name;
    unsigned age;
    QString bloodType;
    QString runk;
    vector<QString> ammunition;


};

#endif // MILITARY_HPP
