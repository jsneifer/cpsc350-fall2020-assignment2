#include <iostream>
#include "Grid.cpp"

using namespace std;

class MirrorGame {
  public:
    MirrorGame(); //default constructor
    MirrorGame(Grid* board); //overloaded
    ~MirrorGame(); //destructor

    void boardTransfer(MirrorGame mg2); //transfers current board over to the mirror game passed
    int getNeighbors(int x, int y); //returns the number of neighbors a specific index has
    void setIndex(int a, int b, bool n); //sets arr[x][y] to given bool
    bool getIndex(int k, int l); //returns bool at index k, l

    Grid getBoard(); //returns the 2D array
    void printBoard(); //prints the 2D array
    void printBoard(string out); //prints 2D array to output file

    bool isStable(); //The grid is not stable if a spot will change in the next generation

  protected:
    Grid* gameBoard;

};
