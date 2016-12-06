#ifndef CHECKERSGAME_H
#define CHECKERSGAME_H

#include "board.h"

class CheckersGame
{
  private:
    Board thisBoard;
  public:
    CheckersGame()
    {
      for(int i=0; i<DIMX; i++)
      {
        for(int j=0; j<DIMY; j++)
        {
          if((i == 0 || i == 2) && (j%2) == 0)
          {
            thisBoard.arr[i][j].setColor(1);
            thisBoard.arr[i][j].setType(1);
          }
          if(i == 1 && (j%2) == 1)
          {
            thisBoard.arr[i][j].setColor(1);
            thisBoard.arr[i][j].setType(1);
          }

          if((i == 5 || i == 7) && (j%2) == 0)
          {
            thisBoard.arr[i][j].setColor(2);
            thisBoard.arr[i][j].setType(1);
          }
          if(i == 6 && (j%2) == 1)
          {
            thisBoard.arr[i][j].setColor(2);
            thisBoard.arr[i][j].setType(1);
          }
        }
      }
      thisBoard.printBoard();
    }
};
#endif
