#pragma once
#include "friendFun.h"
namespace USER_INTERFACE {
#include "UI_message.h"
#include "class_list.h"
#include <iostream>
	using std::cout;
	using std::cin;
	
	template < class T>
	class UserInterface {
	public:
		using Container = typename LIST::List<T>;
	private:
		enum{MAX_ADDING_SIZE = 15};
		Container cont;
	public:
		enum { CommandCount = 5 };
		void create();		//	0
		void read();		//	1
		void update();		//	2
		void deletion();	//	3 
		void edit();		//	4
		void operator[](int index);
	};//class UserInterface<T>;




	template < class T>
	void UserInterface<T>::create()
	{
		create_message();
		int NumOfInputElem, i = 0;
		if (cont.size())
		{
			cont.clear();
		}
		input_check(NumOfInputElem,0, MAX_ADDING_SIZE);
		while (i < NumOfInputElem)
		{
			T inputVal;
			inputVal_message();
			cin >> inputVal;
			cont.push_back(inputVal);
			i++;
		}
	}//	0 
	template <>
	void UserInterface<int>::create()
	{
		create_message();
		int NumOfInputElem, i = 0;
		if (cont.size())
		{
			cont.clear();
		}
		input_check(NumOfInputElem, 0, MAX_ADDING_SIZE);
		while (i < NumOfInputElem)
		{
			int inputVal;
			inputVal_message();
			input_check(inputVal);
			cont.push_back(inputVal);
			i++;
		}
	}//	0

	template < class T>
	void UserInterface <T>::read()
	{
		read_message();
		if(!cont.empty())
		cont.showList();
		read_message_end();
	}		//	1
	template < class T>
	void UserInterface<T>::update()
	{

		update_message();
		int NumOfInputElem, i = 0;
		input_check(NumOfInputElem);
		while (i < NumOfInputElem)
		{
			T inputVal;
			inputVal_message();
			cin >> inputVal;
			cont.push_back(inputVal);
			i++;
		}
	}//2

	template < >
	void UserInterface<int>::update()
	{

		update_message();
		int NumOfInputElem, i = 0;
		input_check(NumOfInputElem,0,MAX_ADDING_SIZE);
		while (i < NumOfInputElem)
		{
			int inputVal;
			inputVal_message();
			input_check(inputVal);
			cont.push_back(inputVal);
			i++;
		}
	}//	2
	template < class T>
	void UserInterface<T>::deletion()
	{
			delete_message();
		if (!cont.empty())
		{
			int DelType;
			input_check(DelType, 0, 2);
			if (DelType == 1)
			{
				delete_one_message();
				int deleteIndex;
				input_check(deleteIndex, 1, cont.size());
				typename Container::iterator delElem = cont[deleteIndex-1];
				cont.erase(delElem);
			}
			if (DelType == 2)
			{
				delete_interval_message();
				int delElemStart, delElemEnd;
				input_check(delElemStart, 1, cont.size());
				input_check(delElemEnd, delElemStart, cont.size());
				typename Container::iterator itStart, itEnd;
				itStart = cont[delElemStart-1];
				itEnd = cont[delElemEnd-1];
				cont.erase(itStart, itEnd);
			}
		}
			return;
	}//	3 
	template < class T>
	void UserInterface<T>::edit()
	{
			edit_message();
		if (!cont.empty())
		{
			int indexEdit;
			input_check(indexEdit, 1, cont.size());
			typename Container::iterator editElem = cont[indexEdit-1];
			T newVal;
			cin >> newVal;
			editElem = cont.erase(editElem);
			cont.insert(editElem, newVal);
		}
	}	//	4
	template < >
	void UserInterface<int>::edit()
	{
		using T = typename int;
		edit_message();
		if (!cont.empty())
		{
			int indexEdit;
			input_check(indexEdit, 1, cont.size());
			typename Container::iterator editElem = cont[indexEdit - 1];
			T newVal;
			inputVal_message();
			input_check(newVal);
			editElem = cont.erase(editElem);
			cont.insert(editElem, newVal);
		}
	}
	template < class T>
	void UserInterface<T>::operator[](int index)
	{
		switch (index)
		{
		case 0:	create();	break;		//	0
		case 1:	read();		break;	//	1
		case 2: update();	break;	//	2
		case 3: deletion();	break;//	3
		case 4:	edit();	break;	//	4
		}
	}
}
