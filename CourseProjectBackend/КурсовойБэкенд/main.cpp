#include <iostream>
#include"Data.h"
int main(void)
{
	std::string s = "password";
	std::cin>>s;
 	DATA::Data h(s);
	std::cout << h.getHashKey();
	return 0;
}