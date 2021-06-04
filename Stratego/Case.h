#ifndef CASE_H
#define CASE_H

#include "Piece.h"

class Case
{
  private:
    bool available;
    Piece piece;

  public:
    /*affecte la Piece p a la case*/
     Case(Piece p);
    /*creer un case vide available vaut 0*/
     Case();


  /*indique si la case est libre*/
    public :bool Isavailable();
    Piece getPiece();
};

#endif
