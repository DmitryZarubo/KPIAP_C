#pragma once
#ifndef JOKE_H
#define JOKE_H
#include <iostream>
#include <stdlib.h>
#include <ctime>
const int N = 30;
class Joke {
private:
	char* text;
	unsigned int rate;
	char* date;
	unsigned int text_size;
	void resize(unsigned int req_size);
	void redate();
	void relocate_arrchar(const char* source, int src_size, char*& dist);
public:
	Joke();
	Joke(const char* _text, const int _rate);
	Joke(const Joke& copy_obj);
	
	void settext(const char* _text);
	void setrate(int _rate);
	
	const char* gettext() const;
	const unsigned int getrate() const;
	const char* getdate() const;
	const unsigned int gettext_size() const;

	Joke& operator=(Joke& obj) ;
	bool operator==(Joke& comp_obj)const;
	bool operator>(Joke& comp_obj)const;
	bool operator<(Joke& comp_obj)const;

	friend std::ostream& operator<< (std::ostream & out, const Joke & joke);
	friend std::istream& operator>> (std::istream& in, Joke& joke);
	
	void edit();
	
	~Joke();
};
#endif