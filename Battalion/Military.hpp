#ifndef MILITARY_HPP
#define MILITARY_HPP
#include <string>
#include <vector>
#include <QString>

#include "ParsingException.hpp"
#include "BadBloodTypeException.hpp"
#include <QJsonObject>
#include <QJsonArray>
#include "LimitedDataLists.hpp"
#include "JsonParsingAddition.hpp"

using namespace std;

class Military
{
public:
//конструктори
    Military();
    Military(unsigned number, const string& surname, const string& name, unsigned age,const string& bloodType,const string& runk,const vector<string>& ammunition);
    Military(const QJsonObject& jsonObj);

//властивості
    Military& setNumber(unsigned number);
    unsigned getNumber() const { return this->number;  }

    Military& setSurname(const string& surname);
    string getSurname() const{ return surname;  }

    Military& setName(const string& name);
    string getName() const { return name;  }

    Military&  setAge(unsigned age);
    unsigned getAge() const {return age;  }

    Military& setBloodType(const string& bloodType);
    string getBloodType()  const {return  bloodType;  }

    Military& setRunk(const string& runk);
    string getRunk() const{return runk; }

    Military& setAmmunition(const vector<string>& ammunition);
    vector<string> getAmmunition() const {return ammunition;  }
private:

    unsigned number;
    string surname;
    string name;
    unsigned age;
    string bloodType;
    string runk;
    vector<string> ammunition;


};

#endif // MILITARY_HPP
