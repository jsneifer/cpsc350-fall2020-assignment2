#include "DoughnutGame.h"


DoughnutGame::DoughnutGame() {
  gameBoard = new Grid();
}

DoughnutGame::DoughnutGame(Grid* board) {
  gameBoard = board;
}

DoughnutGame::~DoughnutGame() {
  delete gameBoard;
}

void DoughnutGame::printBoard() {
    gameBoard->printGrid();
}
void DoughnutGame::printBoard(string out) {
  gameBoard->printGrid(out);
}

Grid DoughnutGame::getBoard() {
  return *gameBoard;
}

void DoughnutGame::setIndex(int a, int b, bool n) {
  gameBoard->setIndex(a, b, n);
}
bool DoughnutGame::getIndex(int k, int l) {
  return gameBoard->getIndex(k, l);
}


void DoughnutGame::boardTransfer(DoughnutGame cg2) {
  for(int i; i < gameBoard->getWidth(); ++i) {
    for(int j; j < gameBoard->getHeight(); ++j) {
      if(this->getNeighbors(i, j) < 2) { // 0-1 neighboring cells is empty
        cg2.setIndex(i, j, false);
      } else if(this->getNeighbors(i, j) == 2) { // 2 neighboring cells stays the same
        cg2.setIndex(i, j, this->getIndex(i, j));
      } else if(this->getNeighbors(i, j) == 3) { // 3 neighboring cells will contain a cell
        cg2.setIndex(i, j, true);
      } else { // 4+ neighboring cells will be empty
        cg2.setIndex(i, j, false);
      }
    }
  }
}

// finds the neighbors of an index based on the rules of the mode
int DoughnutGame::getNeighbors(int x, int y) {
  int neighbors = 0;

  if(x == 0 && y == 0) { // checks if index is in bottom left
    if(gameBoard->getIndex(x,y+1) == true) { //above
      ++neighbors;
    } else if(gameBoard->getIndex(x+1,y) == true) { //right
      ++neighbors;
    } else if(gameBoard->getIndex(x+1,y+1) == true) { //above right
      ++neighbors;
    } else if(gameBoard->getIndex(gameBoard->getWidth(), y) == true) { //right edge, bottom
      ++neighbors;
    } else if(gameBoard->getIndex(gameBoard->getWidth(), y+1) == true) { //right edge, 1 above bottom
      ++neighbors;
    } else if(gameBoard->getIndex(x, gameBoard->getHeight()) == true) { //top, left edge
      ++neighbors;
    } else if(gameBoard->getIndex(x+1, gameBoard->getHeight()) == true) { //top, 1 right of left edge
      ++neighbors;
    } else if(gameBoard->getIndex(gameBoard->getWidth(), gameBoard->getHeight()) == true) { //top right corner
      ++neighbors;
    }
  } else if(x == gameBoard->getWidth()-1 && y == gameBoard->getHeight()-1) { // checks if index is in top right
    if(gameBoard->getIndex(x,y-1) == true) { //below
      ++neighbors;
    } else if(gameBoard->getIndex(x-1,y) == true) { //left
      ++neighbors;
    } else if(gameBoard->getIndex(x-1,y-1) == true) { //below left
      ++neighbors;
    } else if(gameBoard->getIndex(0, y) == true) { //left edge
      ++neighbors;
    } else if(gameBoard->getIndex(0, y-1) == true) { //below left edge
      ++neighbors;
    } else if(gameBoard->getIndex(x, 0) == true) { //right edge bottom
      ++neighbors;
    } else if(gameBoard->getIndex(x-1, 0) == true) { // left of right edge bottom
      ++neighbors;
    } else if(gameBoard->getIndex(0, 0) == true) {
      ++neighbors;
    }
  } else if(y == 0 || y == gameBoard->getHeight() - 1) { // checks if index is on top or bottom of grid
    if(y == 0) { //bottom of the grid
      if(gameBoard->getIndex(x,y+1) == true) { //above
        ++neighbors;
      } else if(gameBoard->getIndex(x+1,y) == true) { //right
        ++neighbors;
      } else if(gameBoard->getIndex(x-1,y) == true) { //left
        ++neighbors;
      } else if(gameBoard->getIndex(x+1,y+1) == true) { //above right
        ++neighbors;
      } else if(gameBoard->getIndex(x-1,y+1) == true) { //above left
        ++neighbors;
      } else if(gameBoard->getIndex(x, gameBoard->getHeight()) == true) { //top middle
        ++neighbors;
      } else if(gameBoard->getIndex(x+1, gameBoard->getHeight()) == true) { //top right
        ++neighbors;
      } else if(gameBoard->getIndex(x-1, gameBoard->getHeight()) == true) { //top left
        ++neighbors;
      }
    } else {
      if(gameBoard->getIndex(x,y-1) == true) { //below
        ++neighbors;
      } else if(gameBoard->getIndex(x+1,y) == true) { //right
        ++neighbors;
      } else if(gameBoard->getIndex(x-1,y) == true) { //left
        ++neighbors;
      } else if(gameBoard->getIndex(x-1,y-1) == true) { //below left
        ++neighbors;
      } else if(gameBoard->getIndex(x+1,y-1) == true) { //below right
        ++neighbors;
      } else if(gameBoard->getIndex(x, 0) == true) { //bottom middle
        ++neighbors;
      } else if(gameBoard->getIndex(x+1, 0) == true) { // bottom right
        ++neighbors;
      } else if(gameBoard->getIndex(x-1, 0) == true) { //bottom left
        ++neighbors;
      }
    }
  } else if(x == 0 || x == gameBoard->getWidth() - 1) { //checks if index is on the right or left
    if(x <= 0) {
      if(gameBoard->getIndex(x,y+1) == true) { //above
        ++neighbors;
      } else if(gameBoard->getIndex(x,y-1) == true) { //below
        ++neighbors;
      } else if(gameBoard->getIndex(x+1,y) == true) { //right
        ++neighbors;
      } else if(gameBoard->getIndex(x+1,y-1) == true) { //below right
        ++neighbors;
      } else if(gameBoard->getIndex(x+1,y+1) == true) { //above right
        ++neighbors;
      } else if(gameBoard->getIndex(gameBoard->getWidth(), y) == true) { //right edge middle
        ++neighbors;
      } else if(gameBoard->getIndex(gameBoard->getWidth(), y+1) == true) { //right edge above
        ++neighbors;
      } else if(gameBoard->getIndex(gameBoard->getWidth(), y-1) == true) { //right edge below
        ++neighbors;
      }
    } else {
      if(gameBoard->getIndex(x,y+1) == true) { //above
        ++neighbors;
      } else if(gameBoard->getIndex(x,y-1) == true) { //below
        ++neighbors;
      } else if(gameBoard->getIndex(x-1,y) == true) { //left
        ++neighbors;
      } else if(gameBoard->getIndex(x-1,y-1) == true) { //below left
        ++neighbors;
      } else if(gameBoard->getIndex(x-1,y+1) == true) { //above left
        ++neighbors;
      } else if(gameBoard->getIndex(0, y) == true) { //left edge middle
        ++neighbors;
      } else if(gameBoard->getIndex(0, y+1) == true) { //left edge above
        ++neighbors;
      } else if(gameBoard->getIndex(0, y-1) == true) { //leftedge below
        ++neighbors;
      }
    }
  } else { // not on an edge: basic logic
    if(gameBoard->getIndex(x,y+1) == true) { //above
      ++neighbors;
    } else if(gameBoard->getIndex(x,y-1) == true) { //below
      ++neighbors;
    } else if(gameBoard->getIndex(x+1,y) == true) { //right
      ++neighbors;
    } else if(gameBoard->getIndex(x-1,y) == true) { //left
      ++neighbors;
    } else if(gameBoard->getIndex(x-1,y-1) == true) { //below left
      ++neighbors;
    } else if(gameBoard->getIndex(x+1,y-1) == true) { //below right
      ++neighbors;
    } else if(gameBoard->getIndex(x+1,y+1) == true) { //above right
      ++neighbors;
    } else if(gameBoard->getIndex(x-1,y+1) == true) { //above left
      ++neighbors;
    }
  }
  return neighbors;
}


bool DoughnutGame::isStable() {
  bool stableCheck = true;

  //iterates through the gameBoard
  for(int j = 0; j < gameBoard->getWidth(); ++j) {
    for(int k = 0; k < gameBoard->getHeight(); ++k) {

      // if the index is empty then check if it is unstable (has more than 2 neighbors)
      if(gameBoard->getIndex(j, k) == false) {
        if(this->getNeighbors(j, k) > 2) {
          stableCheck = false;

          //breaks out of the double nested for loop
          break;
          break;
        }

      // if the index has a cell then check if it has 2-3 neighbors
      } else {
        if(this->getNeighbors(j, k) < 2 || this->getNeighbors(j, k) > 3) {
          stableCheck = false;

          //breaks out of the double nested for loop
          break;
          break;
        }
      }
    }
  }
  return stableCheck;
}
