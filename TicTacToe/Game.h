#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Board.h"

class Game
{
  private:
    Board thisBoard;
    int turn;         //1 or 2 for X or O
  public:
    Game()
    {
      turn = 1;
    }
    bool makeMove(int x, int y)
    {
      if (x<0 || x>2 || y<0 || y>2)
      {
        std::cout << "That is not a legal move, try again!" << std::endl;
        return false;
      }
      if(this->thisBoard.getSpace(x,y) == 0)
      {
        if(this->turn == 1)
        {
          this->thisBoard.setSpace(x,y,'X');
        }
        else
        {
          this->thisBoard.setSpace(x,y,'O');
        }
        if (turn==1)
        {
          turn = 2;
        }
        else
        {
          turn = 1;
        }
        return true;
      }
      else
      {
        std::cout << "That space is taken, try again!" << std::endl;
        return false;
      }
    }
    bool checkVictory()
    {
      char c1, c2, c3;

      for(int i=0; i<8; i++)
      {
        switch(i)
        {
          case 0:
            c1 = this->thisBoard.getSpace(0,0);
            c2 = this->thisBoard.getSpace(1,0);
            c3 = this->thisBoard.getSpace(2,0);
            break;
          case 1:
            c1 = this->thisBoard.getSpace(0,1);
            c2 = this->thisBoard.getSpace(1,1);
            c3 = this->thisBoard.getSpace(2,1);
            break;
          case 2:
            c1 = this->thisBoard.getSpace(0,2);
            c2 = this->thisBoard.getSpace(1,2);
            c3 = this->thisBoard.getSpace(2,2);
            break;
          case 3:
            c1 = this->thisBoard.getSpace(0,0);
            c2 = this->thisBoard.getSpace(0,1);
            c3 = this->thisBoard.getSpace(0,2);
            break;
          case 4:
            c1 = this->thisBoard.getSpace(1,0);
            c2 = this->thisBoard.getSpace(1,1);
            c3 = this->thisBoard.getSpace(1,2);
            break;
          case 5:
            c1 = this->thisBoard.getSpace(2,0);
            c2 = this->thisBoard.getSpace(2,1);
            c3 = this->thisBoard.getSpace(2,2);
            break;
          case 6:
            c1 = this->thisBoard.getSpace(0,0);
            c2 = this->thisBoard.getSpace(1,1);
            c3 = this->thisBoard.getSpace(2,2);
            break;
          case 7:
            c1 = this->thisBoard.getSpace(2,0);
            c2 = this->thisBoard.getSpace(1,1);
            c3 = this->thisBoard.getSpace(0,2);
            break;
        }
        if(c1 == c2 && c2 == c3 && c1 != 0)
        {
          if(this->turn == 1)
          {
            std::cout << "Victory for O's!" << std::endl;
          }
          else
          {
            std::cout << "Victory for X's!" << std::endl;
          }
          return true;
        }
      }
      return false;
    }
    int getTurn()
    {
      return this->turn;
    }
    void printBoardFromGame()
    {
      this->thisBoard.printBoard();
    }
};
#endif
