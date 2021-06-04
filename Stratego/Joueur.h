
#ifndef JOUEUR_H
#define JOUEUR_H

#include "Piece.h"
#include "Plateau.h"

#define NBPIECE 40

class Joueur
{
  private:

    Piece piece[NBPIECE];
    bool color;
    bool turn;

  public:

    Joueur(bool color);

    bool getColor();

    int score(Plateau board);
    int evaluation(Plateau board,Joueur joueur);

    void setupPieces(Plateau &e);
    Piece choixPiece(bool turn,Plateau board);
    void play(bool turn);
};

#endif
