#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board
{
  private:
    char arr[3][3];
  public:
    Board()
    {
      for(int i=0; i<3; i++)
      {
        for(int j=0; j<3; j++)
        {
          this->arr[i][j]=0;
        }
      }
    }
    void printBoard()
    {
      std::cout << "   1   2   3" << std::endl;
      for(int i=0; i<3; i++)
      {
        std::cout << i+1 << " ";
        for(int j=0; j<3; j++)
        {
          if(this->arr[i][j] != 0)
          {
            std::cout << " " << this->arr[i][j] << " ";
          }
          else
          {
            std::cout << "   ";
          }
          if(j<2)
          {
            std::cout << "|";
          }
        }
        if(i<2)
        {
          std::cout << std::endl << "  -----------";
        }
        std::cout << std::endl;
      }
    }
    char getSpace(int x, int y)
    {
      return this->arr[x][y];
    }
    void setSpace(int x, int y, char input)
    {
      this->arr[x][y] = input;
    }
};
#endif
