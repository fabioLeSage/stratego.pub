
#ifndef PIECE_H
#define PIECE_H

#define DRAPEAU 0 //x1 score-win
#define ESPION 1 //x1 score+512
#define ECLAIREUR 2 //x8 score+4
#define DEMINEUR 3 //x5 score+16
#define SERGENT 4 //x4 score+16
#define LIEUTENANT 5 //x4 score+32
#define CAPITAINE 6 //x4 score+64
#define COMMANDANT 7 //x3 score+128
#define COLONEL 8 //x2 score+256
#define GENERAL 9 //x1 score+512
#define MARECHAL 10 //x1 score+1024
#define BOMBE 11 //x6 score+64

#define SCOREMAX 3888 //total score=3888

#define BLUE true
#define RED false

#include "Coord.h"

using namespace std;

class Piece
{
  private:

    Coord position;
    bool color;
    bool inGame;
    std::string name;
    int value;
    bool visible;

  public:

    Piece();/*
    Piece(bool color);
    Piece(bool color, Coord* pos);*/
    Piece(bool color, int value, std::string name, Coord position);

    bool getColor();
    int getValue();
    std::string getName();
    Coord getPosition();
    void setPiece(Coord pos);
    bool canMouv();
    void move( Coord position);
    void setPosition(Coord newPosition);
    bool getInGame();
    bool isBlue();
    bool isRed();
    void reveal(Piece* adversaire);
    bool posStartValid();

};



#endif
