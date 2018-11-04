#include "LimitedDataLists.hpp"

LimitedDataLists* LimitedDataLists::data = nullptr;
LimitedDataLists::LimitedDataLists()
{
    militaryProperties = { "number", "surname","name","age","bloodType","runk","ammunition"};
}
LimitedDataLists& LimitedDataLists::LimitedDataListsSingletone()
{
    if(!LimitedDataLists::data)
    {
        LimitedDataLists::data = new LimitedDataLists();
    }
    return *LimitedDataLists::data;
}
