#include "Data.h"

std::string& DATA::convert_String_to_string(String^ input, std::string& output)// ��������������� � �++ ������
{
    using namespace Runtime::InteropServices;
    const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(input)).ToPointer();
    output = chars;
    Marshal::FreeHGlobal(IntPtr((void*)(chars)));   
    return output;
}

DATA::String^ DATA::convert_string_to_String(const std::string& input, String^ output) //��������������� � ����������� �������� ������
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
 

/*������ ������ Data*/

int DATA::DataB::getExistCodes(int x) // ����� ����������� ������� ����� ����� ��� ��������������� ������-�� ������� � ASCII-����
{
    x += 256;
    while (!(((x < 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97)))) //�������� ������������� �� ������ ��������
        if (x < 48)
            x += 24;
        else
            x -= 47;
    return x; 
}

int DATA::DataB::getControlSum(string str) //����� ������ ����������� ����� ������� ������
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
        size_t minLen = 2; //����������� ����� ������ ���� ������� 2
        size_t realMinLen = 0; //����� ������, ��������� � ������ ����� ���� 
        
        size_t originalSault = this->getControlSum(value); //��������� ���� ������������ ������
        size_t originalLengthStr = (value.size()); //����� ������������ ������
        
        while (minLen <= hashLen) //��������� ����� ������ ������� ������� 2 ��������� � �������� ����� ���� 
            realMinLen = (minLen *= 2);
        
        while (minLen < originalLengthStr) // �������� ��������� � ����� ������ ����� ���� 2^n
            minLen *= 2;

        if ((minLen - originalLengthStr) < minLen) // ������ ����� ���� ��� ������� � 2 ���� ������ �������� �����
            minLen *= 2;
        size_t addCount = minLen - originalLengthStr; //���������� �������� ��� ����� ��������
        //���������� 
        for (int i = 0; i < addCount; i++)
            value += this->getExistCodes(value[i] + value[i + 1]);
        size_t maxSault = this->getControlSum(value);
        size_t maxLengthStr = value.size();
        
        //���������� ����� ������ � ��������� � ����� ����
        while (value.size() != realMinLen)
        {
            for (int i = 0, center = value.size() / 2; i < center; i++)
                this->hash += this->getExistCodes(value[center + i] + value[center - i]);
            value = this->hash;
            this->hash.clear();
        }
        //���������� � ������ ����� 
        size_t difference = realMinLen - hashLen;

        for (size_t i = 0, countCompress = realMinLen / difference; this->hash.size() < (hashLen - 4); i++)
        {
            if (i % countCompress == 0)
                this->hash += this->getExistCodes(value[i] + value[++i]);
            else
                this->hash += value[i];
        }
        //���������� ������������ �����
        this->hash += this->getExistCodes(originalSault);
        this->hash += this->getExistCodes(originalLengthStr);
        //���������� ������������ �����
        this->hash += this->getExistCodes(maxSault);
        this->hash += this->getExistCodes(maxLengthStr);
        this->hash = "https://ZaruboShortener//" + this->hash;
        return this->hash;
    }
    return string();
}
