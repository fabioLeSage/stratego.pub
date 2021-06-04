
#include <iostream>

#include "Coord.h"

// Constructeur
Coord::Coord()
{
  this->x = 0;
  this->y = 0;
}

Coord::Coord(int x, int y)
{
  this->x = x;
  this->y = y;
}

int Coord::getx()
{
  return this->x;
}

int Coord::gety()
{
  return this->y;
}

bool Coord::posValid()
{
  if (!(x >= 0 && x < 10 && y >= 0 && y < 10)) { //position dans le plateau
			return false;
		}
		if(((y==4) || (y==5)) && ((x==2) || (x==3) || (x==6) || (x==7))) { //vérifie sur la position n'est pas interdite (lac)
			return false;
		}
		return true;
}
