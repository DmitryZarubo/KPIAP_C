#include <iostream>
#include "UI_message.h"
using namespace std;
void welcom_message()
{
	system("cls");
	cout <<
		"\tChose what command to perform :\n" <<
		"0 - creat object\n" <<
		"1 - read object to consol\n" <<
		"2 - update objects\n" <<
		"3 - delete objects\n" <<
		"4 - edit your objects\n" <<
		"5 - cancel and choose mode\n";
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
	std::getchar();
}
void update_message()
{
	system("cls");
	cout << "\n\t\t$$$$$$ Update objects $$$$$$$\n" <<
		"\tEnter number of objects you want to add\n";
}
void delete_message()
{
	system("cls");
	cout << "\n\t\t$$$$$$$ Deletion of objects $$$$$$$\n" <<
		"\tChoose how to delete your elements:\n\t#0 - Cancel\n\t#1 - Delete one element\n\t#2 - Delete elements from X to Y interval\n";
}
void delete_one_message()
{
	system("cls");
	cout << "\tEnter an index of deleting element:\n";
}
void delete_interval_message()
{
	system("cls");
	cout << "\tEnter your interval\'s X and Y index\'s:\n";
}
void edit_message()
{
	system("cls");
	cout << "\n\t\t$$$$$$ Editing your objects $$$$$$\n" <<
		"\tEnter index of editing element and then edit it\n";
}
void inputVal_message()
{
	system("cls");
	cout << "Enter your value\n\t";
}
void input_failure_message()
{
	cout << "\n\t!!!!!! Wrong number or invalid symbol : try again !!!!!!\n";
}
void input_number_message(int L_border, int R_border)
{
	cout << "\nEnter your value in the interval from "
		<< L_border << " to " << R_border << " -\t";
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