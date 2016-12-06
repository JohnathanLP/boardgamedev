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
      std::cout << "   ";
      for(char i='A'; i<'I'; i++)
      {
        std::cout << " " << i << "  ";
      }
      std::cout << std::endl;
      for(int i=0; i<DIMX; i++)
      {
        std::cout << i+1 << "  ";
        for(int j=0; j<DIMY; j++)
        {
          if(arr[i][j].getColor() != 0)
          {
            /*
            Note that I have tweaked this a bit for the sake of checkers, I
            eventually want to move the print function to the game level, rather
            than where it is in the board level. I plan for board to be a
            generic class that can be re-used for chess and other games, with
            all of the game-specific logic in the game-specific classes.
            */
            if(arr[i][j].getColor() == 1)
            {
              std::cout << "R," << arr[i][j].getSymbol();
            }
            else if(arr[i][j].getColor() == 2)
            {
              std::cout << "B," << arr[i][j].getSymbol();
            }
            //std::cout << arr[i][j].getColor() << "," << arr[i][j].getSymbol();
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
          std::cout << "   ";
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
