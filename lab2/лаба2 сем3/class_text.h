#pragma once
#ifndef CLASS_TEXT_H
#define CLASS_TEXT_H
#include <iostream>
#include <stdlib.h>
#include <ctime>
class RatedText {
protected:
	char* text;
	int rate;
	unsigned int text_size;
	void resize(unsigned int req_size);
	void relocate_arrchar(const char* source, int src_size, char*& dist);
public:
	RatedText(const char* txt="\0", const int _rate=-1);
	RatedText(const RatedText& copy_obj);
	void settext(const char* _txt);
	void setrate(const int _rate);
	const int getrate() const;
	const char* gettext() const ;
	const unsigned int gettext_size() const;
	virtual void showinfo();
	RatedText& operator=(const RatedText& copy_obj);
	virtual bool operator==(const RatedText& comp_obj)const;
	virtual bool operator!=(const RatedText& comp_obj)const ;
	bool operator>(const RatedText& comp_obj)const;
	bool operator<(const RatedText& comp_obj)const;
	bool operator>=(const RatedText& comp_obj)const;
	bool operator<=(const RatedText& comp_obj)const;
	friend std::istream& operator>>(std::istream& in, RatedText& text);
	friend std::ostream& operator<<(std::ostream& out, const RatedText& text);
	virtual ~RatedText();
};



class Joke : public RatedText {
private:
	enum{N=40};
	char* date; //дата
	void redate(); //передатировка
public:
	Joke(const char* _text="\0", const int _rate=-1);
	Joke(const Joke& copy_obj);
	const char* getdate() const;
	virtual void showinfo();
	Joke& operator=(const Joke& obj);
	virtual bool operator==(const Joke& comp_obj)const;
	virtual bool operator!=(const Joke& comp_obj)const; 
	friend std::ostream& operator<< (std::ostream& out, const Joke& joke);
	friend std::istream& operator>> (std::istream& in, Joke& joke);
	~Joke();
};


class Newspapers : public RatedText 
{
private:
	std::string edition;
	std::string date;
public:
	Newspapers(const char* _text="\0", const char* _edition="\0", const int _rate=-1, const char* date="\0");
	Newspapers(const Newspapers& copy_obj);
	const std::string& get_edition() const;
	const std::string& get_date()const ;
	void set_edition(const char* _edition);
	void set_date(const char* _date);
	virtual void showinfo();
	Newspapers& operator=(const Newspapers& obj);
	friend std::istream& operator>>(std::istream& in, Newspapers& obj);
	friend std::ostream& operator<<(std::ostream& out, const Newspapers& obj);
	~Newspapers() {};
};
#endif