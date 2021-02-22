#include <iostream>
#include "messages.h"
using namespace std;
void start_message()
{
	system("cls");
	cout << "\t\t$$$$$$$\tHello, User!\t$$$$$$$$\n";
	cout << "Choose which class to use :\n"
		<< "\t1 - RatedText (Superclass)\n"
		<< "\t2 - Joke (Subclass)\n"
		<< "\t3 - Newspapers (Subclass)\n"
		<<"\t4 - Exit\n";
	cout << "Enter your command -   ";
}
void welcom_message()
{
	system("cls");
	cout <<
		"\tChose what command to perform :\n" <<
		"0 - creat object\n" <<
		"1 - read object to consol\n" <<
		"2 - update objects\n" <<
		"3 - delete objects\n" <<
		"4 - sort your objects by rate\n" <<
		"5 - edit your objects\n"<<
		"6 - cancel and choose mode\n";
	cout << "\t\tEnter your command";
}
void create_message()
{
	system("cls");
	cout << "\n\t\t$$$$$$\tCreation of objects\t$$$$$$\n" <<
		"\tEnter number of adding elements :\t";
}

void read_message()
{
	system("cls");
	cout << "\n\t\t$$$$$ Read objects $$$$$\n";
	cout << "\n\tThere is our saved objects :\n\n";
}
void read_message_end()
{
	cout << "\n\tEnter something to go back to command screan....\t";
	getchar();
}
void update_message()
{
	system("cls");
	cout << "\n\t\t$$$$$$ Update objects $$$$$$$\n" <<
		"\tEnter number of objects you want to add\n";
}
void deletion_message()
{
	system("cls");
	cout << "\n\t\t$$$$$$$ Deletion of objects $$$$$$$\n" <<
		"\tEnter index of objects you want to delete or enter \"0\" to cancel\n";
}
void sorting_message_begin()
{
	system("cls");
	cout << "\n\t\t$$$$$$$ Sorting of objects $$$$$$$\n"<<
		"\tChose order of sorting...\n"<<
		"\t0 - acending order\n"<<
		"\t1 - decending order\n";
}
void edit_message()
{
	system("cls");
	cout << "\n\t\t$$$$$$ Editing your objects $$$$$$\n" <<
		"\tEnter index of editing objects and then edit it\n";
}
void input_failure_message()
{
	cout << "\n\t!!!!!! Wrong number or invalid symbol : try again !!!!!!\n";
}
void input_number_message(int L_border, int R_border)
{
	cout << "\nEnter your value in the interval from "
		<<L_border<<" to "<<R_border<<" -\t";
}
void input_objects_message()
{
	system("cls");
	cout << "Enter objects values :\n";
}
void end_message()
{
	cout << "\n\n\t\tTHE END.\n\n";
}