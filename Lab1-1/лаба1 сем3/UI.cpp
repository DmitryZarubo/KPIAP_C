#include <iostream>
#include <stdlib.h>
#include "class_joke.h"
#include "UI.h"
#include <vector>
#include "assistfun.h"
#include "sort.h"
#include "messages.h"
#include "preparedJokes.h"
void create(std::vector<Joke>& anekdoti)  // обнуление вектора и внесение в него экземпляров
{
	create_message();	
	int NumOfInputElem;
	if (anekdoti.size())	
		anekdoti.clear();
	input_check(NumOfInputElem);
	anekdoti.reserve(NumOfInputElem);
	for (unsigned int i = 0; i < NumOfInputElem; i++)
	{
		Joke temp;
		input_objects_message();
		std::cin >> temp;
		anekdoti.push_back(temp);
	}
}
void upload_prepared_hahashki(std::vector<Joke>& anekdoti) //загрузка приготовленных шуток
{
	for (int i = 0; i < HAHA::Y; i++)
	{
		anekdoti.push_back(Joke(HAHA::hahashki[i], HAHA::rates[i]));
	}
}
void read(std::vector<Joke>& anekdoti)	//чтение в консоль содержимого вектора
{
	read_message();
	for (unsigned int i = 0; i < anekdoti.size(); i++)
		std::cout <<"\n\n№" <<i+1<<" : " <<anekdoti[i];
	read_message_end();
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}
void update(std::vector<Joke>& anekdoti)	//дополнение в конец вектора экземплярами
{
	update_message();
	Joke temp;
	 int NumOfInputElem;
	input_check(NumOfInputElem);
	for (unsigned int i = 0; i < NumOfInputElem; i++)
	{
		input_objects_message();
		std::cin >> temp;
		anekdoti.push_back(temp);
	}
}
void deletion(std::vector<Joke>& anekdoti)	//удаление шутки по индексу
{
	deletion_message();
	int IndexOfDelElem;
	std::vector<Joke> ::iterator it;
	while (1)
	{
		if (anekdoti.size() == 0)
			return;
		input_check(IndexOfDelElem,0, anekdoti.size());
		IndexOfDelElem -= 1;
		if (IndexOfDelElem == -1)
			break;
		if ((unsigned)IndexOfDelElem > (anekdoti.size() / 2))
		{
			it = anekdoti.end();
			do {
				--it;
			} while (*it != anekdoti[IndexOfDelElem]);
		}
		if ((unsigned)IndexOfDelElem <= (anekdoti.size() / 2))
		{
			it = anekdoti.begin();
			for (it; *it != anekdoti[IndexOfDelElem]; it++);
		}
		anekdoti.erase(it);		
	}
}
void sorting(std::vector<Joke>& anekdoti)	//сортировка 
{
	sorting_message_begin();
	int typeofsort;    
	if (anekdoti.empty())
		return;
	input_check(typeofsort, 0, 1);
	switch (typeofsort)
	{
	case 0: std::sort(anekdoti.begin(), anekdoti.end(),acendingOrder);
		break;
	case 1: std::sort(anekdoti.begin(), anekdoti.end(), decendingOrder);
	}
}
void edit_Joke(std::vector<Joke>& anekdoti) //изменение элементов вектора
{
	edit_message();
	int IndexOfEditingJoke;
	if (anekdoti.empty())
		return;
	input_check(IndexOfEditingJoke, 0, anekdoti.size());
	if (IndexOfEditingJoke == 0)
		return;
	IndexOfEditingJoke -= 1;
	char buf[300];
	int rate = 0;
	input_objects_message();
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.getline(buf, 300);
	anekdoti[IndexOfEditingJoke].settext(buf);
	anekdoti[IndexOfEditingJoke].setrate(input_check(rate, 0, 10));

}