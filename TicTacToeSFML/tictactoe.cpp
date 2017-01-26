#include <iostream>
#include "Game.h"

int main()
{
  Game myGame;
  int rowIn;
  int colIn;
  bool turnDone = false;

  std::cout << "Welcome to the game!" << std::endl;

  do
  {
    std::cout << std::endl << std::endl;
    myGame.printBoardFromGame();
    if(myGame.getTurn() == 1)
    {
      std::cout << "You are X's." << std::endl;
    }
    else
    {
      std::cout << "You are Y's." << std::endl;
    }
    while(!turnDone)
    {
      std::cout << "Pick a collumn: ";
      std::cin >> colIn;
      std::cout << "Pick a row: ";
      std::cin >> rowIn;
      turnDone = myGame.makeMove(rowIn-1, colIn-1);
    }
    turnDone = false;
  } while (!myGame.checkVictory());
}
