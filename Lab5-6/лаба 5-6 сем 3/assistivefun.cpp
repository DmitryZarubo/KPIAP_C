#include <iostream>
#include "messages.h"
int input_check(int& N, int L_border = 0, int R_border = 0)
{


    if (R_border == 0)
        R_border = 10;
    input_number_message(L_border, R_border);
    while (1)
    {
        std::cin >> N;
        if (std::cin.fail() || N<L_border || N>R_border)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
        {

            break;
        }
    }
    std::cin.ignore(32767, '\n');
    return N;
}
char* text_input(char* buf)
{
    int i = 0;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
    do
    {
        std::cin.getline(buf, 300);
    } while (buf[0] == '\0');
    return buf;
}