#include <iostream>
#include"class_text.h"
#include <stdlib.h>
#include <ctime>
#include "assistfun.h"
#include <string>
#include <vector>
#include "UI.h"
using myvec = std::vector<std::reference_wrapper<RatedText>>;
void (*UI_command_list[])(myvec& Vec, const Mode mode) = { create, read, update, deletion, sorting, edit };
int main(void)
{
	Mode modes;
	myvec Objects;
	start_message();
	while (change_mode(modes) != _exitpr)
	{
		welcom_message();
		int command;
		while (input_check(command, 0, 6) != 6)
		{
			UI_command_list[command](Objects, modes);
			welcom_message();
		}
		deletion_vec_objs(Objects);
		Objects.clear();
		start_message();
	}
	end_message();
	return 0;
}