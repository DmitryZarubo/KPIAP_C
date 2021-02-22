#include "Data.h"

int DATA::Data::getExistCodes(int x) // ����� ����������� ������� ����� ����� ��� ��������������� ������-�� ������� � ASCII-����
{
    x += 256;
    while (!(((x < 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97)))) //�������� ������������� �� ������ ��������
        if (x < 48)
            x += 24;
        else
            x -= 47;
    return x;
}

int DATA::Data::getControlSum(string str) //����� ������ ����������� ����� ������� ������
{
    size_t sault = 0, strLen=0;
    while (strLen < str.size())
        sault += int(str[strLen++]);  
    return sault;
}

std::string DATA::Data::doHash(size_t hashLen)
{
    
    if (hashLen > 3 && !value.empty())
    {
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

        return this->hash;
    }
    return string();
}
