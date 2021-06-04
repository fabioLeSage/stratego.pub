#include <iostream>

#include "Case.h"
#include "Piece.h"

using namespace std;


  /*affecte la Piece p a la case*/
Case::Case(Piece p)
  {
    this->piece = p;
    available=0;
  }

Case::Case()
{
  /*this->piece = NULL;*/
  this->available = true;

}
  /*indique si la case est libre*/
bool Case::Isavailable()
{
  if (available==0)
    return false;
  return  true;
}

/*renvoi les information sur le champ piece d'une case*/
Piece Case::getPiece()
{
  return this->piece;
}
