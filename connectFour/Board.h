#ifndef BOARD
#define BOARD

#define WDTH 7
#define HGHT 7

class Board
{
  private:
    int arr[WDTH][HGHT];   //-1 for empty, 0 for red, 1 for black
  public:
    //constructor
    Board()
    {
      for(int i=0; i<HGHT; i++)
      {
        for(int j=0; j<WDTH; j++)
        {
          arr[i][j] = -1;
        }
      }
    }
    //prints the board
    void printBoard()
    {
      for(int i=0; i<HGHT; i++)
      {
        for(int j=0; j<WDTH; j++)
        {
          std::cout << arr[i][j] + 1;
        }
        std::cout << std::endl;
      }
    }
    //places a piece in the given collumn, returns true, returns false for full collumn
    bool makeMove(int col)
    {
      //test if collumn is empty
      if(arr[col][0] > 0)
      {
        return false;
      }
      int temp = 0;
      while(arr[col][temp]+1 < 0 && temp < HGHT-1)
      {
        temp++;
      }
      arr[col][temp] = 5;
      return true;
    }
};
#endif
