#pragma once
#ifndef UI_H
#define UI_H
#include <iostream>
#include <stdlib.h>
#include "class_text.h"
#include "sort.h"
#include <vector>
#include "messages.h"
#include "assistfun.h"
#include "UI.h"

enum Mode {
	_RatedText = 1,
	_Joke = 2,
	_Newspapers = 3,
	_exitpr = 4
};
template<typename Ty>
void create_help(std::vector<std::reference_wrapper<RatedText>>& Vec, const int NumOfInputElem)
{
	for (unsigned int i = 0; i < NumOfInputElem; i++)
	{
		input_objects_message();
		Ty* ho = new Ty;
		std::cin >> *ho;
		std::reference_wrapper<Ty> go = *ho;
		Vec.push_back(go);
	}
}
template <typename Ty>
void edit_help(std::vector<std::reference_wrapper<RatedText>>& Vec, const int IndexOfEditingObj)
{
	edit_message();
	Ty* ho = new Ty;
	std::cin >> *ho;
	std::reference_wrapper<Ty> go = *ho;
	Vec[IndexOfEditingObj] = go;
}
void deletion_vec_objs(std::vector<std::reference_wrapper<RatedText>>& Vec);
Mode& change_mode(Mode& mode);
void create(std::vector<std::reference_wrapper<RatedText>>& Vec, const Mode mode); //	0
void read(std::vector<std::reference_wrapper<RatedText>>& Vec, const Mode mode); //		1
void update(std::vector<std::reference_wrapper<RatedText>>& Vec, const Mode mode); //	2
void deletion(std::vector<std::reference_wrapper<RatedText>>& Vec, const Mode mode); //	3 
void sorting(std::vector<std::reference_wrapper<RatedText>>& Vec, const Mode mode);  //	4
void edit(std::vector<std::reference_wrapper<RatedText>>& Vec, const Mode mode); //5

#endif