#include <cstring>
#include "DynamicString.h"
#include <stdlib.h>

const int MAX_SIZE = (unsigned short) - 1;

///
/// Служебен метод за копиране на обект от тип този клас
///
void DynamicString::copy(const DynamicString& other)
{
    pData = new char[strlen(other.pData) + 1];

    if (!pData)
        std::cerr << "Out of memory!" << std::endl;
    else
        strcpy(pData, other.pData);
}

///
/// Служебен метод за копиране на C-низ
///
void DynamicString::copy(const char* pStr)
{
    pData = new char[strlen(pStr) + 1];

    if (!pData)
        std::cerr << "Out of memory!" << std::endl;
    else
        strcpy(pData, pStr);
}

///
/// Служебен метод за копиране на символ
///
void DynamicString::copy(const char ch)
{
    pData = new char[2];

    if (!pData)
        std::cerr << "Out of memory!" << std::endl;
    else
    {
        *pData = ch;
        *(pData + 1) = '\0';
    }
}

///
/// Служебен метод, който освобождава заделената памет
///
void DynamicString::destroy()
{
    delete[] pData;
}

///
/// Конструктор по подразбиране
///
DynamicString::DynamicString()
{
    pData = new char[2];

    if (!pData)
        std::cerr << "Out of memory!" << std::endl;
    else
        *pData = '\0';
}

///
/// Конструктор за копиране
///
DynamicString::DynamicString(const DynamicString& other)
{
    copy(other);
}

///
/// Конструктор за копиране на C-низ
///
DynamicString::DynamicString(const char* pStr)
{
    copy(pStr);
}

///
/// Конструктор за копиране на символ
///
DynamicString::DynamicString(const char ch)
{
    copy(ch);
}

///
/// Оператор за присвояване
///
DynamicString& DynamicString::operator=(const DynamicString& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

///
/// Оператор за присвояване на C-низ
///
DynamicString& DynamicString::operator=(const char* pStr)
{
    destroy();
    copy(pStr);

    return *this;
}

///
/// Оператор за присвояване на символ
///
DynamicString& DynamicString::operator=(const char ch)
{
    destroy();
    copy(ch);

    return *this;
}

///
/// Деструктор
///
DynamicString::~DynamicString()
{
    destroy();
}

///
/// Връща дължината на низа
///
size_t DynamicString::size() const
{
    return strlen(pData);
}

///
/// Връща символа на дадената позиция
///
char& DynamicString::operator[](size_t pos)
{
    size_t length = strlen(pData);
    return pos < length ? pData[pos] : pData[length - 1];
}
char* DynamicString::GetString()const
{
    return this->pData;
}


///
/// Оператор за равенство на два низа
///
bool operator==(const DynamicString& ds1, const DynamicString& ds2)
{
    return !strcmp(ds1.pData, ds2.pData);
}

///
/// Оператор за равенство на низ и C-низ
///
bool operator==(const DynamicString& ds, const char* str)
{
    return !strcmp(ds.pData, str);
}

///
/// Оператор за равенство на низ и символ
///
bool operator==(const DynamicString& ds, const char ch)
{
    return *ds.pData == ch && *(ds.pData + 1) == '\0';

}

///
/// Оператор за неравенство между два низа
///
bool operator!=(const DynamicString& ds1, const DynamicString& ds2)
{
    return !(ds1 == ds2);
}

///
/// Оператор за неравенство между низ и C-низ
///
bool operator!=(const DynamicString& ds, const char* str)
{
    return !(ds == str);
}

///
/// Оператор за неравенство между низ и символ
///
bool operator!=(const DynamicString& ds, const char ch)
{
    return !(ds == ch);
}

///
/// Оператор за извеждане към изходен поток
///
std::ostream& operator<<(std::ostream& os, const DynamicString& ds)
{
    os << ds.pData;
    return os;
}

///
/// Оператор за въвеждане от входен поток
///
std::istream& operator>>(std::istream& is, DynamicString& ds)
{
    char* pTemp = new char[MAX_SIZE];
    is >> pTemp;
    ds.destroy();
    ds.copy(pTemp);
    delete[] pTemp;
    return is;
}

///
/// Оператор за въвеждане на ред от входен поток
///
std::istream& getline(std::istream& is, DynamicString& ds)
{
    char* pTemp = new char[MAX_SIZE];
    is.getline(pTemp, MAX_SIZE);
    ds.destroy();
    ds.copy(pTemp);
    delete[] pTemp;
    return is;
}
