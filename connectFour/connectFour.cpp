#include <iostream>
#include "Board.h"

int main()
{
  bool gameComplete = false;
  enum ToPlay {red, black};
  ToPlay toPlay = red;
  bool validMove = false;
  int input;
  Board myBoard;

  std::cout << "Welcome to the game!" << std::endl;

  while(!gameComplete)
  {
    switch (toPlay)
    {
      case red:
        std::cout << "Red to play: " << std::endl;
        break;
      case black:
        std::cout << "Black to play: " << std::endl;
        break;
    }
    myBoard.printBoard();
    std::cout << "Select a collumn: ";
    std::cin >> input;
    while(!validMove)
    {
      validMove = myBoard.makeMove(input);
      if(!validMove)
      {
        std::cout << "Try again!" << std::endl;
      }
    }
    validMove = true;

    switch (toPlay)
    {
      case red:
        toPlay = black;
        break;
      case black:
        toPlay = red;
        break;
    }
  }

  return 0;
}
