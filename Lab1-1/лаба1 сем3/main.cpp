#include <iostream>
#include <stdlib.h>
#include "class_joke.h"
#include "sort.h"
#include <vector>
#include "assistfun.h"
#include "UI.h"
#include "messages.h"

int main(void)
{
	setlocale(LC_ALL, "Russian");
	std::vector<Joke> anekdoti; //создаем вектор типа джоук
	int command; //номер команды
	welcom_message();
	while (input_check(command, 0, 7)+1 && command!=7)
	{
		fun_pointer[command](anekdoti);
		welcom_message();
	}
	end_message();
	Joke a;
	a.~Joke();
	return 0;
}