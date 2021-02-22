#include"class_text.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "assistfun.h"
#include <string>



/*                        Реализация класса Text                      */
RatedText::RatedText(const char* _text, const int _rate) //конструктор по умолчанию
{
    unsigned int i = 0;
    this->text_size = 0;
    resize(i);
    if (_rate <= 10 && _rate >= 0)
        this->rate = _rate;
    else
        this->rate = -1;
    while (_text[i] != '\0')
    {
        if (i >= text_size)
            resize(i);
        text[i] = _text[i++];
    }
    text[i] = '\0';
}
RatedText::RatedText(const RatedText& copy_obj)
{
    text_size = copy_obj.text_size;
    rate = copy_obj.rate;
    char* temp = text;
    text = new char[text_size];
    for (unsigned int i = 0; i < text_size; i++)
        text[i] = copy_obj.text[i];
}
void RatedText::relocate_arrchar(const char* source, int src_size, char*& dist) //метод чтобы присваивать массив чаров другому 
{
    unsigned int i = 0;
    delete[] dist;
    char* temp = new char[src_size];
    while (source[i])
    {
        temp[i] = source[i++];
    }
    temp[i] = '\0';
    dist = temp;
}
void RatedText::resize(unsigned int req_size)  //метод для изменения длинны массива чаров
{
    unsigned int new_size = text_size;
    char* new_text;
    if (new_size != 0)
    {
        unsigned int i;
        while (new_size <= req_size)
            new_size += 15;
        new_text = new char[new_size];
        for (i = 0; i < new_size; i++)
            new_text[i] = this->text[i];
        delete[] this->text;
        this->text = new_text;
        this->text_size = new_size;
    }
    if (new_size == 0)
    {
        text = new char[15];
        text_size = 15;
    }
}
void RatedText::settext(const char* _text)       //сеттер текста
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
}
void RatedText::setrate(const int _rate)
{
    this->rate = _rate;
}
const int RatedText::getrate() const
{
    return this->rate;
}
const char* RatedText::gettext()const        //геттер текста
{
    return this->text;
}
const unsigned int RatedText::gettext_size()const //геттер размера текста
{
    return this->text_size;

}
RatedText& RatedText::operator=(const RatedText& obj)
{
    relocate_arrchar(obj.text, obj.text_size, this->text);
    this->text_size = obj.text_size;
    this->rate = obj.rate;
    return *this;
}
bool RatedText::operator==(const RatedText& comp_obj)const
{
    bool flag = 0;
    if (strcmp(this->gettext(), comp_obj.gettext()) == 0)
        if (this->getrate() == comp_obj.getrate())
            flag = 1;
    return flag;
}
bool RatedText::operator!=(const RatedText& comp_obj)const
{
    bool flag = 1;
    if (strcmp(this->gettext(), comp_obj.gettext()) == 0)
        if (this->rate == comp_obj.rate)
                flag = 0;
    return flag;
}
bool RatedText::operator>(const RatedText& comp_obj)const
{
    return (bool)(this->rate > comp_obj.rate);
}
bool RatedText::operator<(const RatedText& comp_obj) const
{
    return (bool)(this->rate < comp_obj.rate);
}
bool RatedText::operator>=(const RatedText& comp_obj)const
{
    return (bool)(this->rate >= comp_obj.rate);
}
bool RatedText::operator<=(const RatedText& comp_obj)const
{
    return (bool)(this->rate <= comp_obj.rate);
}


std::istream& operator>>(std::istream& in, RatedText& text)
{
    char* buf= new char[300];
    int rate = 0;
    std::cout << "Text :\t";
    text.settext(text_input(buf));
    std::cout << "Rate :\t";
    text.setrate(input_check(rate, 0, 10));
    return in;
}
std::ostream& operator<<(std::ostream& out, const RatedText& text)
{
    out <<"Text :\t" <<text.gettext()<< std::endl <<"Rate :\t"<< text.getrate()<<std::endl;
    return out;
}
void RatedText::showinfo()
{
    std::cout<<"\n\tRatedText :\n" << *this;
}
RatedText::~RatedText()
{
    delete[] text;
}





/*                                                         Реaлизация класса Joke                                              */
void Joke::redate()   //переопределение даты изменения
{
    time_t t = time(NULL);
    ctime_s(this->date, N * sizeof(char), &t);
}

/*Конструкторы*/

//Joke::Joke() : RatedText() // конструктор
//{
//    date = new char[N];
//    redate();
//}
Joke::Joke(const char* _text, const int _rate) : RatedText(_text, _rate) //конструктор по умолчанию
{
    this->date = new char[N];
    this->redate();
}
Joke::Joke(const Joke& copy_obj) : RatedText(copy_obj) // конструктор копирования
{
    date = new char[N];
    int i = 0;
    while (copy_obj.date[i] != '\0')
        date[i] = copy_obj.date[i++];
    date[i] = '\0';
}

/*Геттеры*/


const char* Joke::getdate()const       //гетер даты
{
    return this->date;
}


/*Перегруженные операторы*/

Joke& Joke::operator=(const Joke& obj)
{
    RatedText::operator=(obj);
    memcpy(this->date, obj.date, N);
    return *this;
}
bool Joke::operator!=(const Joke& comp_obj)const
{
    bool flag = 1;
    if (strcmp(this->gettext(), comp_obj.gettext()) == 0)
        if (this->getrate() == comp_obj.getrate())
            if (strcmp(this->date, comp_obj.date) == 0)
            flag = 0;
    return flag;
}
bool Joke::operator==(const Joke& comp_obj)const
{
    bool flag = 0;
    if (strcmp(this->gettext(), comp_obj.gettext()) == 0)
        if (this->getrate() == comp_obj.getrate())
            if (strcmp(this->date, comp_obj.date) == 0)
            flag = 1;
    return flag;
}
/*Перегруженные операторы потокового ввода\вывова*/

std::ostream& operator<< (std::ostream& out, const Joke& joke)
{

    out << (const RatedText&)joke<< "Date :\t" << joke.date;
    return out;
}
std::istream& operator>> (std::istream& in, Joke& joke)
{
    in >> (RatedText&)joke;
    joke.redate();
    return in;
}
void Joke::showinfo()
{
    std::cout << "\n\tJoke :\n" << *this;
}
/*Деструктор*/
Joke::~Joke()
{
    delete[] date;
}


/*                                                    Реализация класса Newspapers                          */
//Newspapers::Newspapers() : RatedText()
//{
//    this->edition = "none";
//    this->date = "none";
//    this->setrate(0);
//}

Newspapers::Newspapers(const char* _text, const char* _edition, const int _rate, const char* _date) : RatedText(_text,_rate)
{
    this->edition = _edition;
    this->date = _date;
}
Newspapers::Newspapers(const Newspapers& copy_obj) : RatedText(copy_obj)
{
    this->date = copy_obj.date;
    this->edition = copy_obj.edition;
}
const std::string& Newspapers::get_edition() const
{
    return this->edition;
}
const std::string& Newspapers::get_date()const
{
    return this->date;
}
void Newspapers::set_edition(const char* _edition)
{
    this->edition = _edition;
}
void Newspapers::set_date(const char* _date)
{
    this->date = _date;
}
Newspapers& Newspapers::operator=(const Newspapers& obj) 
{
    RatedText::operator=(obj);
    this->date = obj.date;
    this->edition = obj.edition;
    return *this;
}
std::istream& operator>>(std::istream& in, Newspapers& obj)
{
    char buf[300];
    std::cout << "Edition :\t";
    obj.set_edition(text_input(buf));
    std::cout << "Date :\t";
    obj.set_date(text_input(buf));
    in >> (RatedText&)obj;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Newspapers& obj)
{
    out <<"Editor :  "<< obj.get_edition() << "\nDate :\t" << obj.get_date()  <<std::endl<< (const RatedText&)obj;
    return out;
}
void Newspapers::showinfo()
{
    std::cout <<"\n\tNewspaper :\n"<< *this;
}
