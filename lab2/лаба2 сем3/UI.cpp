#include <iostream>
#include <stdlib.h>
#include "UI.h"
#include <vector>
#include "assistfun.h"
#include "sort.h"
#include "messages.h"
#include "class_text.h"
void deletion_vec_objs(std::vector<std::reference_wrapper<RatedText>>& Vec)
{
	RatedText* ptr;
	for (int i = 0; i < Vec.size(); i++)
	{
		ptr = &Vec[i].get();
		delete ptr;
	}
}
Mode& change_mode(Mode& mode)
{
	int _mode;
	input_check(_mode, 1, 4);
	switch (_mode)
	{
	case _RatedText:	mode = _RatedText; break;
	case _Joke:	mode = _Joke; break;
	case _Newspapers: mode = _Newspapers; break;
	default: mode = _exitpr;
	}
	return mode;
}
void create(std::vector<std::reference_wrapper<RatedText>>& Vec, const Mode mode)  // обнуление вектора и внесение в него экземпляров
{
	create_message();
	int NumOfInputElem;
	if (Vec.size())
	{
		deletion_vec_objs(Vec);
		Vec.clear();
	}
	input_check(NumOfInputElem);
	Vec.reserve(NumOfInputElem);

	switch (mode)
	{
	case _Joke:			 create_help<Joke>(Vec, NumOfInputElem); break;
	case _RatedText:	 create_help<RatedText>(Vec, NumOfInputElem); break;
	case _Newspapers:	  create_help<Newspapers>(Vec, NumOfInputElem); break;
	}
}
void read(std::vector<std::reference_wrapper<RatedText>>& Vec, const Mode mode)	//чтение в консоль содержимого вектора
{
	read_message();
	for (unsigned int i = 0; i < Vec.size(); i++)
	{
		std::cout << "\n\n#" << i + 1 << " : ";
		Vec[i].get().showinfo();
	}
	read_message_end();
	std::cin.clear();
	std::cin.ignore(32767, '\n');
}
void update(std::vector<std::reference_wrapper<RatedText>>& Vec, const Mode mode)	//дополнение в конец вектора экземплярами
{
	update_message();
	int NumOfInputElem;
	input_check(NumOfInputElem);
	switch (mode)
	{
	case _RatedText: create_help<RatedText>(Vec, NumOfInputElem); break;
	case _Joke:  create_help<Joke>(Vec, NumOfInputElem); break;
	case _Newspapers: create_help<Newspapers>(Vec, NumOfInputElem); break;
	}
}
void deletion(std::vector<std::reference_wrapper<RatedText>>& Vec, const Mode mode)	//удаление шутки по индексу
{
	deletion_message();
	int IndexOfDelElem;
	std::vector<std::reference_wrapper<RatedText>> ::iterator it;
	while (1)
	{
		if (Vec.size() == 0)
			return;
		input_check(IndexOfDelElem,0, Vec.size());
		IndexOfDelElem -= 1;
		if (IndexOfDelElem == -1)
			break;
		if ((unsigned)IndexOfDelElem > (Vec.size() / 2))
		{
			it = Vec.end();
			do {
				--it;
			} while ((*it).get() != Vec[IndexOfDelElem].get());
		}
		if ((unsigned)IndexOfDelElem <= (Vec.size() / 2))
		{
			it = Vec.begin();
			for (it; (*it).get() != Vec[IndexOfDelElem].get(); it++);
		}
		Vec.erase(it);
	}
}
void sorting(std::vector<std::reference_wrapper<RatedText>>& Vec, const Mode mode)	//сортировка 
{
	sorting_message_begin();
	int typeofsort;    
	if (Vec.empty())
		return;
	input_check(typeofsort, 0, 1);
	switch (typeofsort)
	{
	case 0: std::sort(Vec.begin(), Vec.end(),acendingOrder);
		break;
	case 1: std::sort(Vec.begin(), Vec.end(), decendingOrder);
	}
}
void edit(std::vector<std::reference_wrapper<RatedText>>& Vec, const Mode mode) //изменение элементов вектора
{
	edit_message();
	int IndexOfEditingObj;
	if (Vec.empty())
		return;
	input_check(IndexOfEditingObj, 0, Vec.size());
	if (IndexOfEditingObj == 0)
		return;
	IndexOfEditingObj -= 1;
	switch (mode)
	{
	case _RatedText: edit_help<RatedText>(Vec, IndexOfEditingObj); break;
	case _Joke: edit_help<Joke>(Vec, IndexOfEditingObj); break;
	case _Newspapers: edit_help<Newspapers>(Vec, IndexOfEditingObj); break;
	}

}