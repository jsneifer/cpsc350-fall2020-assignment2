#ifndef GRID_CPP
#define GRID_CPP
#include <fstream>
#include <string>
#include "Grid.h"

Grid::Grid() {
  grid = new bool*[5];
  for(int a = 0; a < 5; ++a) {
    grid[a] = new bool[5];
  }
  width = 5;
  height = 5;
  area = width * height;
}

Grid::Grid(int w, int h, double den) {
  width = w;
  height = h;
  grid = new bool*[h];
  for(int b; b < h; ++b) {
    grid[b] = new bool[w];
  }

  area = w * h;
  for(int q = 0; q < w; ++q) {
    for(int k = 0; k < h; ++k) {
      grid[q][k] = false;
    }
  }
  int pop = area * den;
  int randx = rand() % h - 1;
  int randy = rand() % w - 1;
  for(int t = 0; t < pop; ++t) {
    while(grid[randx][randy] == true) {
      randx = rand() % (w - 1);
      randy = rand() % (h - 1);
    }
    grid[randx][randy] = true;
  }
  /*
  for(int m = 0; m < w; ++m) {
    for(int n = 0; n < h; ++n) {
      cout << grid[m][n];
    }
     cout << endl;
  }
  */
}

Grid::Grid(string inputFile){
  string tp;
  ifstream File;
  File.open(inputFile);
  if(File.is_open()) {

    File >> height;
    File >> width;
    cout << "Width: " << width << " Height: " << height << endl;
    grid = new bool*[width];
    for(int p = 0; p < width; ++p) {
      grid[p] = new bool[height];
    }
    int row = height;
    while(getline(File, tp)) {
      for(int i = 0; i < tp.size(); ++i) {
        if(tp[i] == '-') {
          grid[row][i] = false;
        } else {
          grid[row][i] = true;
        }
      }
      --row;
    }
  }
  File.close();
}



Grid::~Grid() {
  delete grid;
}

bool** Grid::getGrid() {
  return grid;
}

//Prints to the console
void Grid::printGrid() {
  for(int i = 0; i < height; ++i) {
    for(int j = 0; j < width; ++j) {
      if(grid[i][j] == true) {
        cout << "X";
      } else {
        cout << "-";
      }
    }
    cout << endl;
  }
}

//Prints to an output file
void Grid::printGrid(string outputFile) {

  ofstream outfile;
  outfile.open(outputFile);
  if(outfile.is_open()) {
    for(int i = 0; i < height; ++i) {
      for(int j = 0; j < width; ++j) {
        if(grid[i][j] == true) {
          outfile << "X";
        } else {
          outfile << "-";
        }
      }
      outfile << endl;
    }
  }
  outfile.close();
}

void Grid::setIndex(int x, int y, bool con) {
  grid[x][y] = con;
}

bool Grid::getIndex(int a, int b) {
  return grid[a][b];
}

int Grid::getHeight() {
  return height;
}
int Grid::getWidth() {
  return width;
}
int Grid::getArea() {
  return area;
}


#endif
