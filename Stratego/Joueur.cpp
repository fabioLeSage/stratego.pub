
#include <iostream>

#include "Joueur.h"

#define HUMAN_TURN 1
#define BOT_TURN 0


using namespace std;


Joueur::Joueur(bool color)
{
  for(int i=0;i<40;i++)
  {
    if(i==0)
    {
      this->piece[i] = Piece(color,DRAPEAU,"drapeau",Coord(0,0));
    }
    if(i==1)
    {
      this->piece[i] = Piece(color,ESPION,"ESPION",Coord(0,0));
    }
    if(i>1 && i<11)
    {
      this->piece[i] = Piece(color,ECLAIREUR,"ECLAIREUR",Coord(0,0));
    }
    if(i>10 && i<16)
    {
      this->piece[i] = Piece(color,DEMINEUR,"DEMINEUR",Coord(0,0));
    }
    if(i>15 && i<20)
    {
      this->piece[i] = Piece(color,SERGENT,"SERGENT",Coord(0,0));
    }
    if(i>19 && i<24)
    {
      this->piece[i] = Piece(color,LIEUTENANT,"LIEUTENANT",Coord(0,0));
    }
    if(i>23 && i<28)
    {
      this->piece[i] = Piece(color,CAPITAINE,"CAPITAINE",Coord(0,0));
    }
    if(i>27 && i<30)
    {
      this->piece[i] = Piece(color,COMMANDANT,"COMMANDANT",Coord(0,0));
    }
    if(i>29 && i<32)
    {
      this->piece[i] = Piece(color,COLONEL,"COLONEL",Coord(0,0));
    }
    if(i>31 && i<33)
    {
      this->piece[i] = Piece(color,GENERAL,"GENERAL",Coord(0,0));
    }
    if(i>32 && i<34)
    {
      this->piece[i] = Piece(color,MARECHAL,"MARECHAL",Coord(0,0));
    }
    if(i>33 && i<40)
    {
      this->piece[i] = Piece(color,BOMBE,"BOMBE",Coord(0,0));
    }
  }
}

void Joueur::setupPieces(Plateau &board)
{
  cout << "Choix piece placer :" << endl;

  int x(-1);
  int y(-1);

  for(int i=0;i<40;i++)
  {
    int valide(0);
    while(valide!=1){

      cin >> x;
      cin.ignore();
      cin >> y;
      cin.ignore();
      Coord pos = Coord(x,y);
      if(pos.posValid() && board.getCase(pos).Isavailable())
      {
        this->piece[i].setPiece(pos);
      }
      else
      {
        cout << "ce n'est pas une position valide" << endl;
      }
    }
  }
}

Piece Joueur::choixPiece(bool turn,Plateau board){

  if (turn == HUMAN_TURN)
  {

    cout << "Choix piece jouer :" << endl;

    int x(-1);
    int y(-1);

    int valide(0);
    while(valide!=1){

      cin >> x;
      cin.ignore();
      cin >> y;
      cin.ignore();
      Coord pos = Coord(x,y);

      for(int i=0;i<40;i++)
      {
        if(pos.getx() == this->piece[i].getPosition().getx() && pos.gety() == this->piece[i].getPosition().gety())
          {
            valide++;
            return this->piece[i];
          }
        else
        {
          cout << "ce n'est pas une piece valide" << endl;
        }
      }
    }
  }
  /*if (turn == BOT_TURN)
  {
    int score(0);
    int bestScore(0);
    Piece firstMouv;

    firstMouv = this->piece[0];
    for(int i=0;i<40;i++)
    {
      //score = this->score(turn);

      if(score.nextScore(mouv) >= score)
      {
        mouv = this.piece[i]
        return mouv;
      }
    }
    return firstMouv;
  }*/
}

/*int Joueur::score(Plateau board)
{
  int pts(SCOREMAX/2);
  for(int i = 0; i<40; i++)
  {
    if(!this->piece[i].inGame())
    {
      switch (this->piece[i].getValue()) {
        case 1:
          pts-=512
          break;
        case 2:
          pts-=4
          break;
        case 3:
          pts-=16
          break;
        case 4:
          pts-=16
          break;
        case 5:
          pts-=32
          break;
        case 6:
          pts-=64
          break;
        case 7:
          pts-=128
          break;
        case 8:
          pts-=256
          break;
        case 9:
          pts-=512
          break;
        case 10:
          pts-=1024
          break;
        case 11:
          pts-=64
          break;
        default:
          pts=0;
          cout << "défaite du joueur" << endl;
          ingame = false;
          break;
        }
    }
  }
  return pts;
}*/

/*int Joueur::evaluation(Joueur j2,Plateau board)
{
  if (j1.scoreJoueur(board)<j2.scoreJoueur(board)){
    return 1;
  }
  if (j1.scoreJoueur(board)>j2.scoreJoueur(board)){
    return 2;
  }
  else return 0;
}*/

/*void Joueur::play(bool turn)
{

}*/
