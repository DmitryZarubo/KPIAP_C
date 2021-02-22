#include "Data.h"

std::string& DATA::convert_String_to_string(String^ input, std::string& output)// конвертирование в С++ строку
{
    using namespace Runtime::InteropServices;
    const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(input)).ToPointer();
    output = chars;
    Marshal::FreeHGlobal(IntPtr((void*)(chars)));   
    return output;
}

DATA::String^ DATA::convert_string_to_String(const std::string& input, String^ output) //конвертирование в управляемую системой строку
{
    output = gcnew String(input.c_str());
    return output;
}
std::string DATA::convert_String_to_string(String^ input)
{
   std::string output ;
    using namespace Runtime::InteropServices;
    const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(input)).ToPointer();
    output = chars;
    Marshal::FreeHGlobal(IntPtr((void*)(chars)));
    return output;
}

DATA::String^ DATA::convert_string_to_String(const std::string& input)
{
    String^ output = gcnew String(input.c_str());
    return output;
}
 

/*Методы класса Data*/

int DATA::DataB::getExistCodes(int x) // метод преобразует входное число чтобы оно соответствовало какому-то символу в ASCII-коде
{
    x += 256;
    while (!(((x < 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97)))) //проверка соответствует ли нужным символам
        if (x < 48)
            x += 24;
        else
            x -= 47;
    return x; 
}

int DATA::DataB::getControlSum(string str) //метод выдает контрольную сумму вводной строки
{
    size_t sault = 0, strLen=0;
    while (strLen < str.size())
        sault += int(str[strLen++]);  
    return sault;
}

std::string DATA::DataB::doHash(size_t hashLen)
{
    
    if (hashLen > 3 && !value.empty())
    {
        std::string value = DataB::value;
        size_t minLen = 2; //минимальная длина строки хеша кратная 2
        size_t realMinLen = 0; //длина строки, ближайшая к нужной длине хеша 
        
        size_t originalSault = this->getControlSum(value); //получение соли оригинальной строки
        size_t originalLengthStr = (value.size()); //длина оригинальной строки
        
        while (minLen <= hashLen) //получение длины строки кратной степени 2 ближайшей к заданной длине хеша 
            realMinLen = (minLen *= 2);
        
        while (minLen < originalLengthStr) // получаем ближайшее к длине строки число типа 2^n
            minLen *= 2;

        if ((minLen - originalLengthStr) < minLen) // делаем длину хеша как минимум в 2 раза больше исходной длины
            minLen *= 2;
        size_t addCount = minLen - originalLengthStr; //количество символов что нужно добавить
        //добавление 
        for (int i = 0; i < addCount; i++)
            value += this->getExistCodes(value[i] + value[i + 1]);
        size_t maxSault = this->getControlSum(value);
        size_t maxLengthStr = value.size();
        
        //приведение длины строки к ближайшей к длине хеша
        while (value.size() != realMinLen)
        {
            for (int i = 0, center = value.size() / 2; i < center; i++)
                this->hash += this->getExistCodes(value[center + i] + value[center - i]);
            value = this->hash;
            this->hash.clear();
        }
        //приведение к нужной длине 
        size_t difference = realMinLen - hashLen;

        for (size_t i = 0, countCompress = realMinLen / difference; this->hash.size() < (hashLen - 4); i++)
        {
            if (i % countCompress == 0)
                this->hash += this->getExistCodes(value[i] + value[++i]);
            else
                this->hash += value[i];
        }
        //добавление оригинальных солей
        this->hash += this->getExistCodes(originalSault);
        this->hash += this->getExistCodes(originalLengthStr);
        //добавление максимальных солей
        this->hash += this->getExistCodes(maxSault);
        this->hash += this->getExistCodes(maxLengthStr);
        this->hash = "https://ZaruboShortener//" + this->hash;
        return this->hash;
    }
    return string();
}
