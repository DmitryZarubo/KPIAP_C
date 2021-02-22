#pragma once
#include <algorithm>
#include "class_text.h"
#ifndef SORT_H
#define SORT_H
static auto decendingOrder{
	[](const std::reference_wrapper<RatedText>& comp_obj1,  const std::reference_wrapper<RatedText>& comp_obj2)
	{
		return comp_obj1.get() > comp_obj2.get();
}
};
static auto acendingOrder{
	[](const std::reference_wrapper<RatedText>& comp_obj1,  const std::reference_wrapper<RatedText>& comp_obj2)
	{
		return comp_obj1.get() < comp_obj2.get();
}
};
#endif