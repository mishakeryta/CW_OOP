#include "LimitedDataLists.hpp"

LimitedDataLists* LimitedDataLists::data = nullptr;
LimitedDataLists::LimitedDataLists()
{
    militaryProperties = { "number", "surname","name","age","bloodType","runk","ammunition"};
    bloodTypes = { "1-" , "1+" ,"2-" ,"2+" ,"3-" ,"3+" ,"4-" ,"4+" };
}
LimitedDataLists& LimitedDataLists::Get()
{
    if(!LimitedDataLists::data)
    {
        LimitedDataLists::data = new LimitedDataLists();
    }
    return *LimitedDataLists::data;
}
