#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

#define WIDE 640 //25 tiles
#define HIGH 640 //20 tiles

#define POS1 48
#define POS2 248
#define POS3 448

int main()
{
  //creates a Window object, intializes its size and name
  sf::RenderWindow window(sf::VideoMode(WIDE, HIGH), "TicTacToe");

  sf::Texture backTexture;
  if(!backTexture.loadFromFile("composite.png"))
  {
    std::cout << "error loading textures" << std::endl;
  }
  backTexture.setRepeated(true);
  backTexture.setSmooth(true);
  sf::Sprite background;
  background.setTexture(backTexture);
  background.setTextureRect(sf::IntRect(0, 0, WIDE, HIGH));

  window.draw(background);

  sf::Texture xandoTexture;
  if(!xandoTexture.loadFromFile("xando.png"))
  {
    std::cout << "error loading textures" << std::endl;
  }
  xandoTexture.setSmooth(true);

  sf::Sprite xSprite;
  xSprite.setTexture(xandoTexture);
  xSprite.setTextureRect(sf::IntRect(0, 0, 160, 160));

  sf::Sprite oSprite;
  oSprite.setTexture(xandoTexture);
  oSprite.setTextureRect(sf::IntRect(0, 161, 160, 160));

  sf::Font font;
  if(!font.loadFromFile("raidercrusadershiftdown.ttf"))
  {
    //error
  }

  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(48);
  text.setColor(sf::Color::White);
  text.setOrigin(10,20);
  text.setPosition(WIDE/2,HIGH/2);

  Game myGame;
  int rowIn;
  int colIn;
  int mouseX;
  int mouseY;
  int moveX;
  int moveY;
  bool turnDone = false;
  bool moveMade = false;
  int turn = 0;

  //gameloop: runs until window is closed
  while(window.isOpen())
  {
    //creates event object
    sf::Event event;
    //iterates through all events that have happened in the window
    while(window.pollEvent(event))
    {
      //handles close events
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }
      if (event.type == sf::Event::MouseButtonPressed)
      {
          if (event.mouseButton.button == sf::Mouse::Left)
          {
              // std::cout << "the left button was pressed" << std::endl;
              // std::cout << "mouse x: " << event.mouseButton.x << std::endl;
              // std::cout << "mouse y: " << event.mouseButton.y << std::endl;
              mouseX = event.mouseButton.x;
              mouseY = event.mouseButton.y;
              //collumn 1
              if(POS1 <= mouseX && mouseX <= POS1+160)
              {
                moveX = 0;
              }
              //collumn 2
              else if(POS2 <= mouseX && mouseX <= POS2+160)
              {
                moveX = 1;
              }
              //collumn 3
              else if(POS3 <= mouseX && mouseX <= POS3+160)
              {
                moveX = 2;
              }

              //row 1
              if(POS1 <= mouseY && mouseY <= POS1+160)
              {
                moveY = 0;
              }
              //row 2
              else if(POS2 <= mouseY && mouseY <= POS2+160)
              {
                moveY = 1;
              }
              //row 3
              else if(POS3 <= mouseY && mouseY <= POS3+160)
              {
                moveY = 2;
              }
              std::cout << "Move made: " << moveX << "," << moveY << std::endl;
              if(myGame.makeMove(moveX, moveY))
              {
                if(turn == 0)
                {
                  if(moveX == 0)
                  {
                    if(moveY == 0)
                    {
                      xSprite.setPosition(POS1,POS1);
                      window.draw(xSprite);
                    }
                    else if(moveY == 1)
                    {
                      xSprite.setPosition(POS1,POS2);
                      window.draw(xSprite);
                    }
                    else if(moveY == 2)
                    {
                      xSprite.setPosition(POS1,POS3);
                      window.draw(xSprite);
                    }
                  }
                  else if(moveX == 1)
                  {
                    if(moveY == 0)
                    {
                      xSprite.setPosition(POS2,POS1);
                      window.draw(xSprite);
                    }
                    else if(moveY == 1)
                    {
                      xSprite.setPosition(POS2,POS2);
                      window.draw(xSprite);
                    }
                    else if(moveY == 2)
                    {
                      xSprite.setPosition(POS2,POS3);
                      window.draw(xSprite);
                    }
                  }
                  else if(moveX == 2)
                  {
                    if(moveY == 0)
                    {
                      xSprite.setPosition(POS3,POS1);
                      window.draw(xSprite);
                    }
                    else if(moveY == 1)
                    {
                      xSprite.setPosition(POS3,POS2);
                      window.draw(xSprite);
                    }
                    else if(moveY == 2)
                    {
                      xSprite.setPosition(POS3,POS3);
                      window.draw(xSprite);
                    }
                  }
                  turn = 1;
                }
                else if(turn == 1)
                {
                  if(moveX == 0)
                  {
                    if(moveY == 0)
                    {
                      oSprite.setPosition(POS1,POS1);
                      window.draw(oSprite);
                    }
                    else if(moveY == 1)
                    {
                      oSprite.setPosition(POS1,POS2);
                      window.draw(oSprite);
                    }
                    else if(moveY == 2)
                    {
                      oSprite.setPosition(POS1,POS3);
                      window.draw(oSprite);
                    }
                  }
                  else if(moveX == 1)
                  {
                    if(moveY == 0)
                    {
                      oSprite.setPosition(POS2,POS1);
                      window.draw(oSprite);
                    }
                    else if(moveY == 1)
                    {
                      oSprite.setPosition(POS2,POS2);
                      window.draw(oSprite);
                    }
                    else if(moveY == 2)
                    {
                      oSprite.setPosition(POS2,POS3);
                      window.draw(oSprite);
                    }
                  }
                  else if(moveX == 2)
                  {
                    if(moveY == 0)
                    {
                      oSprite.setPosition(POS3,POS1);
                      window.draw(oSprite);
                    }
                    else if(moveY == 1)
                    {
                      oSprite.setPosition(POS3,POS2);
                      window.draw(oSprite);
                    }
                    else if(moveY == 2)
                    {
                      oSprite.setPosition(POS3,POS3);
                      window.draw(oSprite);
                    }
                  }
                  turn = 0;
                }
              }
          }
      }

    }

    if(myGame.checkVictory())
    {
      if(turn == 0)
      {
        text.setString("O's Win!");
      }
      else if(turn == 1)
      {
        text.setString("X's Win!");
      }
      window.draw(text);
      window.display();
    }

    //updates the window with the new stuff
    window.display();
  }
}
