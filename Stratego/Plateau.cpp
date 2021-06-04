
#include <iostream>
#include "Plateau.h"
#include "Piece.h"
#include "Case.h"

using namespace std;

/* Constructeur: initialise a vide les case du plateau*/
/*case - est vide*/
Plateau::Plateau(Case *c)
{
  Case ca= *c;
  int i,j;
  for(i=0; i<10; i++ ){
    for(j=0; j<10; j++){
     plateau[i][j]=ca; /*les cases du plateau */
    }
  }
}

/*fonction a utliser pour placer les pieces en debut de parti.
  requiert que p est non NULL
  est la coordonéée d'une case du tableau
  elle doit etre comprise entre les 40 1ere cases ou les 40 derniere cases
  c est une case du plateau : c =getCase(pos) */
void Plateau::setupPieces(Case case_du_plateau, Piece p, Coord pos)
{
  if((case_du_plateau.Isavailable())==true){//si c est libre
    case_du_plateau = Case(p);           //on initialise a la valeur de la piece, cette case n'est plus valide(available vaut 0)
    plateau[pos.getx()][pos.gety()]=case_du_plateau;
  }
  else
    cout << "cette case est deja occupé par une de vos pieces\n" << endl;
  /*return this->cases;*/
}

Case Plateau::getCase(Coord pos)
{
  Case res= plateau[pos.getx()][pos.gety()];
  return res;
}


Case Plateau::freePos(Coord pos) /*remet une case*/
{
  Case vide = Case();
  plateau[pos.getx()][pos.gety()]= vide;
  return plateau[pos.getx()][pos.gety()];
}


/*prend une piece et l'affecte a une case de coordonée pos*/
void Plateau::mouvPiece(Piece p, Coord newpos, Coord oldpos)/*bouge une piece du plateau */
{
  /*si la piece est sur le terrain
    on afecte p a position pos du plateau*/
    Case tmp = Case(p);
    plateau[newpos.getx()][newpos.gety()]=tmp;

  /*on libere l'ancienne case*/
  freePos(oldpos);
}


/*retire la piece du plateau, cette fonction est a utilisé apres la fonction reveal
--> regarde le champs in game de la piece a si 0 on libere la case*/
void Plateau::removePiece(Piece p) /*retire une piece du plateau */
{
    if(p.getInGame()==false)/*si p n'est plus en jeux*/
    {
      int x = p.getPosition().getx(), y=p.getPosition().gety() ;  /*recuper les coordonée de p*/
      Case p= Case();                                 /*crée une case vide p*/
      this->plateau[x][y]= p;                              /*affecte p a une case du tableau */
    }
}



/*affichage du plateau a l'ecran */
void Plateau::printPlateau()  /* affiche le plateau*/
{
  int i,j;
  for(i=0; i<10; i++){
    for (j=0; j<10; j++){
      if(plateau[i][j].Isavailable()==true)
        std::cout<<"|________|"; /*une case vide*/
      else
        std::cout<<plateau[i][j].getPiece().getName();
    }
    cout << endl;
  }
}




/*
definir une class case
definir les operation/methode de la class case
definir une casse plateau qui contiendra un tableau de case
gerer aussi l'affichage du plateau:
 des couleur bleu et rouge pour differencier les pieces des joueurs
 une couleurs pour le plateau

Qu'est-ce qu'une case ? Quels information on doit avoir sur une case ?
 -la postion de la case
 -le contenue de cette case
  Que peut contenir une case ?
   - elle peut ne rien contenir
   - elle peut contenir une Piece
   - elle peut contenir un lac, dans ce cas la case n'est pas acessible par les Pieces


Le plateau :
  ça va etre une matrice qui ressemblera à une grille
*/
