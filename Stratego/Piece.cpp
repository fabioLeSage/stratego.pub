
#include <iostream>
#include "Piece.h"
#include "Plateau.h"

Piece::Piece(){
  this->inGame =1;
  this->visible=true;
}/*

Piece(bool color){
  this->color = color;
  this->inGame =1;
  this->visible=true;
}
Piece(bool color, Coord* pos)
{
  this->color = color;
  this->position = *position;
  this->inGame =1;
  this->visible=true;
}*/

Piece::Piece(bool color, int value, std::string name, Coord position) {
    this->color = color;
    this->position = position;
    this->value = value;
    this->name = name;
    this->inGame =1;
    this->visible=true;
}

//getters
bool Piece::getInGame(){
    return this->inGame;
}

bool Piece::isBlue(){
    if(this->color == BLUE)
        return true;
    return false;
}

bool Piece::isRed(){
    if( (this->color) == RED)
        return true;
    return false;
}

bool Piece::getColor()  {
    return this->color;
}

int Piece::getValue()  {
  return this->value;
}

std::string Piece::getName()  {
  return this->name;
}

void Piece::setPiece(Coord pos){
  this->position=pos;
}

Coord Piece::getPosition(){
    return this->position;
}

bool Piece::canMouv(){
    if ( (this->value != DRAPEAU) && (this->value=!BOMBE) )
        return true;
    return false ;
}

void Piece::setPosition( Coord newPosition) {
    this->position = newPosition;
}

void Piece::reveal(Piece* adversaire){
    if(this->position.getx() == adversaire->position.getx() && this->position.gety() == adversaire->position.gety())
    {
        if (this->value == adversaire->value ){
            this->inGame=0;
            adversaire->inGame=0;
        }
        else if (this->value < adversaire->value){
            this->inGame=0;
            adversaire->visible=false;
        }
        else
        {
          adversaire->inGame=0;
          this->visible=false;
        }
    }

}

void Piece::move(Coord newPosition) {
    if(this->canMouv()) {
        this->position = newPosition;
      }
}

bool Piece::posStartValid()
{
  if((this->position.posValid() == false)){
    return false;
  }

  if((this->position.gety()>5 && this->getColor() == BLUE)){
    return false;
  }

  if((this->position.getx()<4 && this->getColor() == RED)){
    return false;
  }

  return true;
}
/*
void Piece::setPiece(Coord* pos){
    this->position=pos ;
}



void Piece::reveal(Piece adversaire){
    if(this->position == adversaire->position )
    {
        if (this->value == adversaire->value ){
            this->inGame=0;
            adversaire->inGame=0;
        }
        else if (this->value < adversaire->value)
            this->inGame=0;
            else  adversaire->inGame=0;

    }

} */
