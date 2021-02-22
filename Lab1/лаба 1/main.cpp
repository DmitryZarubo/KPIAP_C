#include <iostream>
#include <stdlib.h>
#include "class_joke.h"
int main()
{
	Joke j;
	Joke j1("werrew", 32);
	Joke j2;
	j.settext("fdsafsafsafsa");
	j.setrate(12);
	Joke h;
	h = j;
	std::cin >> j2;
	std::cout << h <<j <<j1 << j2;
	std::cout << j.gettext() <<" "<< j.getdate()<<" "<< j.getrate() <<" "<< j.gettext_size();
	return 0;
}