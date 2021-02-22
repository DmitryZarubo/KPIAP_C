#include <iostream>
#include "classes.h"
using namespace std;
void  correct_input(istream& in,int& variable)
{
	while (1)
	{
		try {
			in >> variable;
			if (in.fail())
				throw Tank::bad_input();
			break;
		}
		catch (Tank::bad_input bad)
		{
			in.clear();
			in.ignore(23242, '\n');
			cout << bad.what();
			continue;
		}
	}
		in.clear();
		in.ignore(23242, '\n');
}
istream& operator>>(istream& in, Tank& tank)
{
	int dam, spd;
	char arm[512];
	correct_input(in,dam);
	correct_input(in,spd);
	in.getline(arm, 512);
	tank.setArmor(arm);
	tank.setDamage(dam);
	tank.setSpeed(spd);
	return in;
}
ostream& operator<<(ostream& out,const Tank& tank)
{
	out << "Armor : " << tank.getArmor() << endl << "Max Damage : " << tank.getDamage() <<
		endl << "Max Speed : " << tank.getSpeed();
	return out;
}