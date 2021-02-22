#pragma once
#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include "myException.h"
#include <exception>

	class Tank {
	public:
		class bad_input :public std::exception
		{
		public:
			bad_input( const char* what_arg = "Incorrect input : please repeat input operation - \t") :exception(what_arg) {};
		};
	protected:
		int  max_speed;
		int max_damage;
		char armor_type[40];
	public:
		Tank(int speed = 0, int damage = 0, const char* armor = "none") : max_speed(speed), max_damage(damage) { strcpy_s(armor_type, armor); };
		friend std::istream& operator>>(std::istream& in, Tank& tank);
		friend std::ostream& operator<<(std::ostream& out, const Tank& tank);
		const int& getSpeed()const { return max_speed; };
		const int& getDamage() const { return max_damage; };
		const char* getArmor() const  { return armor_type; };
		void setSpeed(const int& speed) { max_speed = speed; };
		void setDamage(const int& damage) { max_damage = damage; };
		void setArmor(const char* armor) { strcpy_s(armor_type , armor); };

	};

#endif