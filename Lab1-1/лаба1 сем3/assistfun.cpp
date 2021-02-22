#include <iostream>
#include <stdlib.h>
#include "class_joke.h"
#include "sort.h"
#include <vector>
#include "messages.h"
int input_check(int& N, int L_border = 0, int R_border = 0)
{
    if (R_border == 0)
        R_border = 10;
    while (1)
    {
        input_number_message(L_border,R_border);
        std::cin >> N;
        if (std::cin.fail() || N<L_border || N>R_border)
        {
            input_failure_message();
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
            break;
    }
    return N;
}