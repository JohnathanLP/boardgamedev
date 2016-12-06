#include "checkersgame.h"
#include <iostream>
#include <string>

int main()
{
  CheckersGame myGame;
  myGame.fillBoard();
  int players = myGame.getPlayers();
  int turn = 0;
  bool gameDone = false;
  bool turnDone = false;
  bool flag = false;
  std::string input;

  while(!gameDone)
  {
    myGame.printBoardFromGame();
    if(turn%2 == 0)
    {
      //NOTE THAT IN ALL OTHER CODE, RED IS REFERRED TO AS WHITE
      std::cout << "Red to Move" << std::endl;
    }
    if(turn%2 == 1)
    {
      std::cout << "Black to Move" << std::endl;
    }
    while (!turnDone)
    {
      std::cout << "Select a piece to move: ";
      std::cin >> input;
      //TODO protect these inputs
      int x = input[0]-97;
      int y = input[1]-49;
      if(x < 0 || x > 7 || y < 0 || y > 7 || input.size() < 2)
      {
        std::cout << "This is not a legal input. Inputs should be in the form rowcollumn, for example, a8 or e1" << std::endl << std::endl;
      }
      else
      {
        turnDone = myGame.makeMove(x, y, (turn%2)+1);
      }
      //std::cout << "TESTING:" << x << " " << y << " " << (turn%2)+1 << std::endl;
    }
    turnDone = false;
    turn++;
  }
}
