#include "MirrorGame.h"

MirrorGame::MirrorGame() {
  gameBoard = new Grid();
}

MirrorGame::MirrorGame(Grid* board) {
  gameBoard = board;
}

MirrorGame::~MirrorGame() {
  delete gameBoard;
}

void MirrorGame::printBoard() {
    gameBoard->printGrid();
}
void MirrorGame::printBoard(string out) {
  gameBoard->printGrid(out);
}

Grid MirrorGame::getBoard() {
  return *gameBoard;
}

void MirrorGame::setIndex(int a, int b, bool n) {
  gameBoard->setIndex(a, b, n);
}
bool MirrorGame::getIndex(int k, int l) {
  return gameBoard->getIndex(k, l);
}




void MirrorGame::boardTransfer(MirrorGame mg2) {
  for(int i; i < gameBoard->getWidth(); ++i) {
    for(int j; j < gameBoard->getHeight(); ++j) {
      if(this->getNeighbors(i, j) < 2) { // 0-1 neighboring cells is empty
        mg2.setIndex(i, j, false);
      } else if(this->getNeighbors(i, j) == 2) { // 2 neighboring cells stays the same
        mg2.setIndex(i, j, this->getIndex(i, j));
      } else if(this->getNeighbors(i, j) == 3) { // 3 neighboring cells will contain a cell
        mg2.setIndex(i, j, true);
      } else { // 4+ neighboring cells will be empty
        mg2.setIndex(i, j, false);
      }
    }
  }
}

int MirrorGame::getNeighbors(int x, int y) {
  int neighbors = 0;

  if(x <= 0 && y <= 0) { // checks if index is in bottom left
    if(gameBoard->getIndex(x,y+1) == true) { //above
      ++neighbors;
    } else if(gameBoard->getIndex(x+1,y) == true) { //right
      ++neighbors;
    } else if(gameBoard->getIndex(x+1,y+1) == true) { //above right
      ++neighbors;
    } else if(gameBoard->getIndex(x, y) == true) { //mirrored orginal
      neighbors += 3;
    } else if(gameBoard->getIndex(x, y+1) == true) { //mirrored above
      ++neighbors;
    } else if(gameBoard->getIndex(x+1, y) == true) { //mirrored below
      ++neighbors;
    }
  } else if(x >= gameBoard->getWidth() && y >= gameBoard->getHeight()) { // checks if index is in top right
    if(gameBoard->getIndex(x,y-1) == true) { //below
      ++neighbors;
    } else if(gameBoard->getIndex(x-1,y) == true) { //left
      ++neighbors;
    } else if(gameBoard->getIndex(x-1,y-1) == true) { //below left
      ++neighbors;
    } else if(gameBoard->getIndex(x, y) == true) { //mirrored orginal
      neighbors += 3;
    } else if(gameBoard->getIndex(x, y-1) == true) { //mirrored above
      ++neighbors;
    } else if(gameBoard->getIndex(x-1, y) == true) { //mirrored below
      ++neighbors;
    }
  } else if(y <= 0 || y >= gameBoard->getHeight() - 1) { // checks if index is on top or bottom of grid
    if(y <= 0) {
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
      } else if(gameBoard->getIndex(x, y) == true) { //mirrored orginal
        ++neighbors;
      } else if(gameBoard->getIndex(x+1, y) == true) { //mirrored above
        ++neighbors;
      } else if(gameBoard->getIndex(x-1, y) == true) { //mirrored below
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
      } else if(gameBoard->getIndex(x, y) == true) { //mirrored orginal
        ++neighbors;
      } else if(gameBoard->getIndex(x, y+1) == true) { //mirrored above
        ++neighbors;
      } else if(gameBoard->getIndex(x, y-1) == true) { //mirrored below
        ++neighbors;
      }
    }
  } else if(x <= 0 || x >= gameBoard->getWidth() - 1) { //checks if index is on the right or left
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
      } else if(gameBoard->getIndex(x, y) == true) { //mirrored orginal
        ++neighbors;
      } else if(gameBoard->getIndex(x, y+1) == true) { //mirrored above
        ++neighbors;
      } else if(gameBoard->getIndex(x, y-1) == true) { //mirrored below
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
      } else if(gameBoard->getIndex(x, y) == true) { //mirrored orginal
        ++neighbors;
      } else if(gameBoard->getIndex(x, y+1) == true) { //mirrored above
        ++neighbors;
      } else if(gameBoard->getIndex(x, y-1) == true) { //mirrored below
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

bool MirrorGame::isStable() {
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
