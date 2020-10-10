
#include "Game.cpp"
#include "Grid.cpp"

using namespace std;

int main() {

  Game* life = new Game();
  life->runGame();
  delete life;

  return 0;
}
