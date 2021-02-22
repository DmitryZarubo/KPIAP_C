#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "class_joke.h"

                                            /* private methods for work only within class*/
void Joke::relocate_arrchar(const char* source, int src_size, char*& dist) //method for swaping strings
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
void Joke::resize(unsigned int req_size)  //method for reallocing memory for field text
{
    unsigned int new_size = text_size;
    char* new_text;
    if (new_size != 0)
    {
        while (new_size <= req_size)
            new_size += 15;
        new_text = new char[new_size];
        for (unsigned int i = 0; i < new_size; i++)
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
void Joke::redate()   //method for changing date after editing an object 
{
    time_t t = time(NULL);
    ctime_s(this->date, N, &t);
}

                /*Constructors*/

Joke::Joke() // constructor
{
    text = new char[15];
    text_size = 15;
    rate = 0;
    date = new char[N];
    redate();
}
Joke::Joke(const char* _text = "\0" , const int _rate=0) //constructor by default
{
    unsigned int i = 0;
    this->text_size = 0;
    while (_text[i]!='\0')
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
Joke::Joke(const Joke& copy_obj) // copy constructor
{
    text_size = copy_obj.text_size;
    text = new char[text_size];
    for (unsigned int i = 0; i < text_size; i++)
        text[i] = copy_obj.text[i];
    rate = copy_obj.rate;
    date = new char[N];
    for (unsigned int i = 0; i < text_size; i++)
        date[i] = copy_obj.date[i];
}

                    /*Setters*/

void Joke::settext(const char* _text)       //text setter
{
   unsigned int i = 0;
    while (_text[i] != '\0')
    {
        if (i >= this->text_size)
            resize(i);
        this->text[i] = _text[i++];
    }
    this->text[i] = '\0';
    redate();
}
void Joke::setrate(int _rate)   // rate setter
{
    rate = _rate;
    redate();
}

                /*Getters*/

const char* Joke::gettext()const        //text getter
{   
    return this->text;
}
const unsigned int Joke::getrate()const // rate getter
{
    return this->rate;
}
const char* Joke::getdate()const       //date getter
{
    return this->date;
}
const unsigned int Joke::gettext_size()const
{
    return this->text_size;
}

                /*Overloaded operators*/
    
Joke& Joke::operator=(Joke& obj)
{
    relocate_arrchar(obj.text, obj.text_size, this->text);
    this->text_size = obj.text_size;
    relocate_arrchar(obj.date, N, this->date);
    this->rate = obj.rate;
    return *this;
}
bool Joke::operator==(Joke& comp_obj)const
{
    return (bool)(this->rate==comp_obj.rate);
}
bool Joke::operator>(Joke& comp_obj)const
{
    return (bool)(this->rate > comp_obj.rate);
}
bool Joke::operator<(Joke& comp_obj) const
{
    return (bool)(this->rate < comp_obj.rate);
}

            /*Overloaded output\input streams*/

std::ostream& operator<< (std::ostream& out, const Joke& joke)
{
    out << "Joke :\t" << joke.text << "\nrate : \t" << joke.rate << "\nwas added :\t" << joke.date;
    return out;
}
std::istream& operator>> (std::istream& in, Joke& joke)
{
    char buf[300];
    unsigned int size=0,i=0;
    in.getline(buf, 300);
    in >> joke.rate;
    size = in.gcount();
    while (i < size)
    {
        if (size >= joke.text_size)
            joke.resize(size);
        joke.text[i] = buf[i++];
    }
    joke.redate();
    return in;
}

            /*Destructor*/

Joke::~Joke()
{
    delete[] text; 
    delete[] date;
}
