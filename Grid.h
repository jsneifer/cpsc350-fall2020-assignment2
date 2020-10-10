#ifndef GRID_H
#define GRID_H
#include <iostream>
using namespace std;

class Grid {
  public:
    Grid(); //default constructor
    Grid(int w, int h, double den); //overloaded
    Grid(string textfile); //second overloaded
    ~Grid(); //destructor

    //Assignment operator
    Grid& operator = (const Grid& g);

    bool** getGrid(); //returns the 2D array
    void printGrid(); //prints 2D array to console
    void printGrid(string outputFile); //prints 2D array to output file
    void setIndex(int x, int y, bool con); //sets boolean at index [x][y] to con

    int getWidth(); // returns the width of the grid
    int getHeight(); //returns the height of the grid
    int getArea(); //returns the area of the grid
    bool getIndex(int a, int b); //returns boolean at the index of the grid

    int area;
    int width;
    int height;

  protected:
    bool** grid;
};
#endif
