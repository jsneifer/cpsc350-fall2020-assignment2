#include <iostream>
#include "Grid.cpp"
#include <algorithm>


//Classes ClassicGame, DoughnutGame, and MirrorGame
// each contain rules for finding the number of neighbors
#include "ClassicGame.cpp"
#include "DoughnutGame.cpp"
#include "MirrorGame.cpp"


using namespace std;

class Game {
  public:
    Game();
    Game(int gO, string file);
    ~Game();

    void runGame(); // Runs the game until the Grid is stable or infinitely
    void GenerationC(ClassicGame *transferFROM, ClassicGame *transferTO); //Executes board transfer
    void GenerationM(MirrorGame *transferFROM, MirrorGame *transferTO); //Executes board transfer
    void GenerationD(DoughnutGame *transferFROM, DoughnutGame *transferTO); //Executes board transfer


  private:

    /*
    Normal Game: gameOptions = 0
    Pause Between Generations: gameOptions = 1
    Enter Between Generations: gameOptions = 2
    */
    int gameOptions;

    //Output to file outFile
    string outFile;
};
