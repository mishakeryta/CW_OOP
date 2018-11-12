#include "LimitedDataLists.hpp"

LimitedDataLists* LimitedDataLists::data = nullptr;
LimitedDataLists::LimitedDataLists()
{
    militaryProperties = { "number", "surname","name","age","bloodType","runk","ammunition"};
    bloodTypes = { "1-" , "1+" ,"2-" ,"2+" ,"3-" ,"3+" ,"4-" ,"4+" };
    runks = {"Солдат","Старший солдат","Молодший сержант"	,"Сержант","Старший сержант","Старшина","Прапорщик","Старший прапорщик",
                "Молодший лейтенант","Лейтенант","Старший лейтенант","Капітан",
             "Майор","Підполковник","Полковник","Генерал-майор","Генерал-лейтенант","Генерал-полковник","Генерал армії України"};
    automatic = {"Adaptive Combat Rifle",
                 "AEK-971",
                 "AG-043",
                 "Ak 5",
                 "AK-9",
                 "AK-47",
                 "AK-74",
                 "AK-101",
                 "AK-102",
                 "AK-103",
                 "AK-107",};
    pistols = {"The Glock",
                   "The Browning Hi Power",
                   "The CZ 75B",
                   "The S&W Shield",
                   "Springfield XD",
                   "Sig P226",
                   "The Walther P99 AS",
                   "The Beretta 92FS",
                   "Heckler and Koch VP9",
                   "Ruger SR9"};
    grenadeLauncher = {  "GLX 160 A1",
                     "GP-34",
                     "K11",
                     "M203",
                     "M320",
                     "MK 13",
                     "DP-64",
                     "MGL",
                     "PAW-20",
                     "RG-6",
                     "XM25",
                     "AGS-30",
                     "GMG"};
}
LimitedDataLists& LimitedDataLists::Get()
{
    if(!LimitedDataLists::data)
    {
        LimitedDataLists::data = new LimitedDataLists();
    }
    return *LimitedDataLists::data;
}
