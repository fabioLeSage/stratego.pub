
#ifndef PLATEAU_H
#define PLATEAU_H

#include "Piece.h"
#include "Case.h"

#define NBCASE 100

class Plateau
{
  private:

    Case* plateau[NBCASE];/*les cases du plateau */

  public:

    Plateau(Case*);

    Coord* getPosition(Piece* p);/*donne la position d'une piece*/
    Case freePos(Coord pos);/*remet une case a vide*/

    Case getCase(Coord pos); /*retourne la case de coordonée pos*/
    void setupPieces(Case c,Piece p, Coord pos); /*les pieces que le joueurs place en debut de parti*/
    void mouvPiece(Piece p, Coord newpos, Coord oldpos);/*bouge une piece du plateau */
    void removePiece(Piece p); /*retire une piece du plateau */

    void printPlateau();  /* affiche le plateau*/
    void resetPlateau(); /*supprime le tableau*/

};

#endif
