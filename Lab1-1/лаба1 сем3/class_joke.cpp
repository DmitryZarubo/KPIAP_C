#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "class_joke.h"
#include "assistfun.h"
#include <string>

/* приватные методы класса*/
void Joke::relocate_arrchar(const char* source, int src_size, char*& dist) //метод чтобы присваивать массив чаров другому 
{
    unsigned int i = 0;
    char* temp = new char[src_size];
    while (source[i])
    {
        temp[i] = source[i++];
    }
    temp[i] = '\0';
    dist = temp;
}
void Joke::resize(unsigned int req_size)  //метод для изменения длинны массива чаров
{
    unsigned int new_size = text_size;
    char* new_text;
    if (new_size != 0)
    {
        unsigned int i;
        while (new_size <= req_size)
            new_size += 15;
        new_text = new char[new_size];
        for ( i = 0; i < new_size; i++)
            new_text[i] = this->text[i];
        delete[] this->text;
        this->text = new_text;
        this->text_size = new_size;
    }
    if (new_size == 0)
    {
        text_size = +15;
        text = new char[text_size];
    }
}
void Joke::redate()   //переопределение даты изменения
{
    time_t t = time(NULL);
    ctime_s(this->date, N*sizeof(char), &t);
}

/*Конструкторы*/

Joke::Joke() // конструктор
{
    text = new char[15];
    for (int i = 0; i < 15; text[i++] = '\0');
    text_size = 15;
    rate = 0;
    date = new char[N];
    redate();
}
Joke::Joke(const char* _text = "\0", const int _rate = 0) //конструктор по умолчанию
{
    unsigned int i = 0;
    this->text_size = 0;
    while (_text[i] != '\0')
    {
        if (i >= text_size)
            resize(i);
        text[i] = _text[i++];
    }
    text[i] = '\0';
    this->date = new char[N];
    this->redate();
    rate = _rate;
}
Joke::Joke(const Joke& copy_obj) // конструктор копирования
{
    text_size = copy_obj.text_size;
    text = new char[text_size];
    for (unsigned int i = 0; i < text_size; i++)
        text[i] = copy_obj.text[i];
    rate = copy_obj.rate;
    date = new char[N];
    int i = 0;
    while(copy_obj.date[i]!='\0')
        date[i] = copy_obj.date[i++];
    date[i] = '\0';
}

/*Сеттеры*/

void Joke::settext(const char* _text)       //сеттер текста
{
    unsigned int i = 0;
    if (text[i])
    {
        while (text[i])
            text[i++] = '\0';
    }
    i = 0;
    while (_text[i] != '\0')
    {
        if (i >= this->text_size)
            resize(i);
        this->text[i] = _text[i++];
    }
    this->text[i] = '\0';
    redate();
}
void Joke::setrate(int _rate)   // сеттер рейтинга
{
    rate = _rate;
    redate();
}

/*Геттеры*/

const char* Joke::gettext()const        //геттер текста
{
    return this->text;
}
const unsigned int Joke::getrate()const // геттер рейтинга
{
    return this->rate;
}
const char* Joke::getdate()const       //гетер даты
{
    return this->date;
}
const unsigned int Joke::gettext_size()const //геттер размера текста
{
    return this->text_size;
}

/*Перегруженные операторы*/

Joke& Joke::operator=(const Joke& obj)
{
    relocate_arrchar(obj.text, obj.text_size, this->text);
    this->text_size = obj.text_size;
    relocate_arrchar(obj.date, N, this->date);
    this->rate = obj.rate;
    return *this;
}
bool Joke::operator==(const Joke& comp_obj)const
{
    bool flag=0;
    if (strcmp(this->text, comp_obj.text) == 0)
        if (this->rate == comp_obj.rate)
            if (strcmp(this->date, comp_obj.date) == 0)
                flag = 1;
    return flag;
}
bool Joke::operator>(const Joke& comp_obj)const
{
    return (bool)(this->rate > comp_obj.rate);
}
bool Joke::operator<(const Joke& comp_obj) const
{
    return (bool)(this->rate < comp_obj.rate);
}
bool Joke::operator>=(const Joke& comp_obj)const
{
    return (bool)(this->rate >= comp_obj.rate);
}
bool Joke::operator<=(const Joke& comp_obj)const
{
    return (bool)(this->rate <= comp_obj.rate);
}
bool Joke::operator!=(const Joke& comp_obj)const
{
    bool flag = 1;
    if (strcmp(this->text, comp_obj.text) == 0)
        if (this->rate == comp_obj.rate)
            if (strcmp(this->date, comp_obj.date) == 0)
                flag = 0;
    return flag;
}

/*Перегруженные операторы потокового ввода\вывова*/

std::ostream& operator<< (std::ostream& out, const Joke& joke)
{
    out << "\tJoke :\n" << joke.text << "\n\trate : \t" << joke.rate << "\n\twas added :\t" << joke.date;
    return out;
}
std::istream& operator>> (std::istream& in, Joke& joke)
{
    char buf[300];
    int size = 0, i;
    in.clear();
    in.ignore(32767, '\n');
    do
    {
        in.getline(buf, 300);
    } while (buf[0]=='\0');
    joke.setrate(input_check(i,0,10));
    joke.settext(buf);
    joke.redate();
    return in;
}

/*Деструктор*/

Joke::~Joke()
{
    delete[] text;
    delete[] date;
}
