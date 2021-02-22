#include<iostream>
#include "class_iterator.h"
#include "class_list.h"
#include "UI_message.h"
#include "class_UI.h"
using namespace std;
using namespace NODE;
using namespace LIST_ITERATOR;
using namespace LIST;
using MyList = typename LIST::List<int>;
void showList(MyList list);
int main(void)
{
	welcom_message();
	USER_INTERFACE::UserInterface<int> UI;
	int command;
	while ((input_check(command, 0, UI.CommandCount)) != (UI.CommandCount))
	{
		UI[command];
		welcom_message();
	}
	end_message();
}
/* мюдекюрэ рпюи\йервеб */