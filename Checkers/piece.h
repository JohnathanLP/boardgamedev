#ifndef PIECE_H
#define PIECE_H

enum pieceID {blank, checker};
enum colorID {none, white, black};

class Piece
{
  private:
    char symbol;
    pieceID type;
    colorID color;
  public:
    Piece()
    {
      color = none;
      symbol = ' ';
    }
    Piece(int colorIn)
    {
      setColor(colorIn);
      symbol = ' ';
    }
    Piece(int colorIn, int typeIn)
    {
      setColor(colorIn);
      setType(typeIn);
    }
    int getColor()
    {
      return color;
    }
    char getSymbol()
    {
      return symbol;
    }
    //REMOVE THIS
    void setType(int typeIn)
    {
      switch (typeIn)
      {
        case 0:
          type = blank;
          symbol = ' ';
          break;
        case 1:
          type = checker;
          symbol = 'c';
          break;
      }
    }
    void setColor(int colorIn)
    {
      switch (colorIn)
      {
        case 0:
          color = none;
          break;
        case 1:
          color = white;
          break;
        case 2:
          color = black;
          break;
      }
    }
};

#endif
