#pragma once
#ifndef UI_H
#define UI_H
#include <iostream>
#include <stdlib.h>
#include "class_joke.h"
#include "sort.h"
#include <vector>
#include "assistfun.h"
#include "UI.h"
void create(std::vector<Joke>& anekdoti); //	0
void upload_prepared_hahashki(std::vector<Joke>& anekdoti); // 1
void read(std::vector<Joke>& anekdoti); //		2
void update(std::vector<Joke>& anekdoti); //	3
void deletion(std::vector<Joke>& anekdoti); //	4 
void sorting(std::vector<Joke>& anekdoti);  //	5
void edit_Joke(std::vector<Joke>& anekdoti); //6
static void (*fun_pointer[])(std::vector<Joke>& anekdoti) = {create,upload_prepared_hahashki, read, update, deletion, sorting, edit_Joke};
#endif