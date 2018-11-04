#ifndef MILITARY_HPP
#define MILITARY_HPP
#include <string>
#include <vector>
#include <QString>

#include "ParsingException.hpp"
#include "BadBloodTypeException.hpp"
#include <QJsonObject>
#include "LimitedDataLists.hpp"

using namespace std;

class Military
{
public:
//конструктори
    Military();
    Military(unsigned number, const string& surname, const string& name, unsigned age,unsigned bloodType,string runk,const vector<string>& ammunition);
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

    Military& setBloodType(unsigned bloodType);
    unsigned getBloodType()  const {return  bloodType;  }

    Military& setAmmunition(const vector<string>& ammunition);
    vector<string> getAmmunition() const {return ammunition;  }
private:
    unsigned number;
    string surname;
    string name;
    unsigned age;
    unsigned bloodType;
    string runk;
    vector<string> ammunition;

};

#endif // MILITARY_HPP
