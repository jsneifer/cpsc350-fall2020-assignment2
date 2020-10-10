#include <iostream>
#include "Grid.cpp"

using namespace std;

class DoughnutGame {
  public:
    DoughnutGame(); //default constructor
    DoughnutGame(Grid* board); //overloaded
    ~DoughnutGame(); //destructor

    void boardTransfer(DoughnutGame dg2); //transfers current board over to the doughnut game passed
    int getNeighbors(int x, int y);

    void printBoard(); //Prints the grid
    void printBoard(string out); //prints 2D array to output file
    Grid getBoard(); //returns the 2D array
    void setIndex(int a, int b, bool n); //sets arr[x][y] to given bool
    bool getIndex(int k, int l); //returns bool at index k, l

    bool isStable(); //The grid is not stable if a spot will change in the next generation

  protected:
    Grid* gameBoard;

};
