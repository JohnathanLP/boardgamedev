#ifndef CHECKERSGAME_H
#define CHECKERSGAME_H

#include "board.h"

class CheckersGame
{
  private:
    Board thisBoard;
    const static int players = 2;
  public:
    CheckersGame()
    {
      fillBoard();
      //thisBoard.printBoard();
    }
    void fillBoard()
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

          if((i == 5 || i == 7) && (j%2) == 1)
          {
            thisBoard.arr[i][j].setColor(2);
            thisBoard.arr[i][j].setType(1);
          }
          if(i == 6 && (j%2) == 0)
          {
            thisBoard.arr[i][j].setColor(2);
            thisBoard.arr[i][j].setType(1);
          }
        }
      }
    }
    bool makeMove(int x, int y, int color)
    {
      if(thisBoard.arr[y][x].getColor() == 0)
      {
        std::cout << "There is no piece there!" << std::endl << std::endl;
        return false;
      }
      else if(thisBoard.arr[y][x].getColor() != color)
      {
        std::cout << "That isn't your piece!" << std::endl << std::endl;
        return false;
      }
      else
      {
        std::cout << "TESTING: That is your piece!" << std::endl;
        //Red
        if(color == 1)
        {
          if(thisBoard.arr[y+1][x+1].getColor() != 0 || thisBoard.arr[y+1][x-1].getColor() != 0)
          {
            std::cout << "That piece has no open moves, try again! " << std::endl << std::endl;
            return false;
          }
        }
        //Black
        if(color == 2)
        {
          if(thisBoard.arr[y-1][x+1].getColor() != 0 || thisBoard.arr[y-1][x-1].getColor() != 0)
          {
            std::cout << "That piece has no open moves, try again! " << std::endl << std::endl;
            return false;
          }
        }
        std::cout << "TESTING: That piece has one or more legal moves!" << std::endl << std::endl;
        return true;
      }
    }
    //returns number of players allowed for this game
    int getPlayers()
    {
      return players;
    }
    void printBoardFromGame()
    {
      thisBoard.printBoard();
    }
};
#endif
