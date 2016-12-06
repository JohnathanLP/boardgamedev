#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <iostream>

#define DIMX 8
#define DIMY 8

class Board
{
  private:

  public:
    /*
    This is the array that stores the location of pieces on the board. For now,
    the size is static at 8x8.
    */
    Piece arr[DIMX][DIMY];
    //Constructor, creates a blank board
    Board()
    {
      // for(int i=0; i<DIMX; i++)
      // {
      //   for(int j=0; j<DIMY; j++)
      //   {
      //     arr[i][j].;
      //   }
      // }
    }
    void printBoard()
    {
      for(int i=0; i<DIMX; i++)
      {
        for(int j=0; j<DIMY; j++)
        {
          if(arr[i][j].getColor() != 0)
          {
            std::cout << arr[i][j].getColor() << "," << arr[i][j].getSymbol();
            if(j<7)
            {
              std::cout << "|";
            }
          }
          else
          {
            if(j<7)
            {
              std::cout << "   |";
            }
            else
            {
              std::cout << "    ";
            }
          }
        }
        std::cout << std::endl;
        if(i<(DIMX-1))
        {
          for(int j=0; j<DIMX; j++)
          {
            std::cout << "----";
          }
          std::cout << std::endl;
        }
      }
    }
};

#endif
