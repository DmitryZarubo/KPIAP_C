#include <iostream>
#include "messages.h"
using namespace std;
void welcom_message()
{
	system("cls");
	cout << "\t\t$$$$$$$\tHello, User!\t$$$$$$$$\n";
	cout <<
		"\tChose what command to perform :\n" <<
		"0 - creat anekdoti\n" <<
		"1 - upload prepared anekdoti\n"<<
		"2 - read anekdoti to consol\n" <<
		"3 - update anekdoti\n" <<
		"4 - delete anekdoti\n" <<
		"5 - sort your anekdoti by rate\n" <<
		"6 - edit your jokes\n"<<
		"7 - cancel and end your program\n";
	cout << "\t\tEnter your command";
}
void create_message()
{
	system("cls");
	cout << "\n\t\t$$$$$$\tCreation of anekdoti\t$$$$$$\n" <<
		"\tEnter number of adding elements -\t";
}

void read_message()
{
	system("cls");
	cout << "\n\t\t$$$$$ Read anekdoti $$$$$\n";
	cout << "\n\tThere is our saved anekdoti :\n\n";
}
void read_message_end()
{
	cout << "\n\tEnter something for return to command screan....\t";
	getchar();
}
void update_message()
{
	system("cls");
	cout << "\n\t\t$$$$$$ Update anekdoti $$$$$$$\n" <<
		"\tEnter number of anekdot's you want to add\n";
}
void deletion_message()
{
	system("cls");
	cout << "\n\t\t$$$$$$$ Deletion ankdoti $$$$$$$\n" <<
		"\tEnter index of anecdot you want to delete or enter \\0\\ to cancel\n";
}
void sorting_message_begin()
{
	system("cls");
	cout << "\n\t\t$$$$$$$ Sorting your anekdoti $$$$$$$\n"<<
		"\tChose order of sorting...\n"<<
		"\t0 - acending order\n"<<
		"\t1 - decending order\n";
}
void edit_message()
{
	system("cls");
	cout << "\n\t\t$$$$$$ Editing your jokes $$$$$$\n" <<
		"\tEnter index of editing joke and then edit it\n";
}
void input_failure_message()
{
	cout << "\n\t!!!!!! Wrong number or invalid symbol : try again !!!!!!\n";
}
void input_number_message(int L_border, int R_border)
{
	cout << "\n\tEnter your value in the interval from "
		<<L_border<<" to "<<R_border<<" -\t";
}
void input_objects_message()
{
	cout << "\n\tEnter your joke and then rate of this joke :\n";
}
void end_message()
{
	cout << "\n\n\t\tTHE END.\n\n";
}