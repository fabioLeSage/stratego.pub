
#ifndef COORD_H
#define COORD_H

class Coord
{
  public:

    int x;
    int y;

    Coord();
    Coord(int x, int y);

    int getx();
    int gety();
    bool posValid();

};

#endif
