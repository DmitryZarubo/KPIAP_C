#pragma once
#include <algorithm>
#include "class_joke.h"
#ifndef SORT_H
#define SORT_H
static auto decendingOrder{
	[](const Joke& comp_obj1,  const Joke& comp_obj2)
	{
		return comp_obj1 > comp_obj2;
}
};
static auto acendingOrder{
	[](const Joke& comp_obj1,const Joke& comp_obj2) 
	{
		return comp_obj1 < comp_obj2;
}
};
#endif