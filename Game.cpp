#include "Game.h"
#include <cstdlib>
#include <unistd.h>
using namespace std;

//default constructor
Game::Game() {
  gameOptions = 0;
  outFile = "";
}
Game::Game(int gO, string file){
  gameOptions = gO;
  outFile = file;
}
Game::~Game() {

}

//GenerationC runs the simulation for Class ClassicGame
void Game::GenerationC(ClassicGame *transferFROM, ClassicGame *transferTO) {
    for(int g = 0; !transferFROM->isStable() || !transferTO->isStable(); ++g) {

      //Transfers Grid from transferFROM to transferTO
      cout << "\nGeneration: " << g << endl;
      if(outFile == "") {
        transferFROM->printBoard();
      } else {
        transferFROM->printBoard(outFile);
      }

      if(gameOptions == 1) {
        sleep(2);
        transferFROM->boardTransfer(*transferTO);
      } else if(gameOptions == 0) {
        cout << "\nHit enter to progress" << endl;
        cin.get();
        transferFROM->boardTransfer(*transferTO);
      } else {
        transferFROM->boardTransfer(*transferTO);
      }

      //Transfers back from transferTO to transferFROM
      if(transferFROM->isStable() || !transferTO->isStable()) {
        ++g;
        cout << "\nGeneration: " << g << endl;
        if(outFile == "") {
          transferTO->printBoard();
        } else {
          transferTO->printBoard(outFile);
        }

        if(gameOptions == 1) {
          sleep(2);
          transferTO->boardTransfer(*transferFROM);
        } else if(gameOptions == 0) {
          cout << "\nHit enter to progress" << endl;
          cin.get();
          transferTO->boardTransfer(*transferFROM);
        } else {
          transferTO->boardTransfer(*transferFROM);
        }
      } else {
        break;
      }
    }

}
//GenerationM runs the simulation for Class MirrorGame
void Game::GenerationM(MirrorGame *transferFROM, MirrorGame *transferTO) {
  for(int g = 0; !transferFROM->isStable() || !transferTO->isStable(); ++g) {

    //Transfers Grid from transferFROM to transferTO
    cout << "\nGeneration: " << g << endl;
    if(outFile == "") {
      transferFROM->printBoard();
    } else {
      transferFROM->printBoard(outFile);
    }

    if(gameOptions == 1) {
      sleep(2);
      transferFROM->boardTransfer(*transferTO);
    } else if(gameOptions == 0) {
      cout << "\nHit enter to progress" << endl;
      cin.get();
      transferFROM->boardTransfer(*transferTO);
    } else {
      transferFROM->boardTransfer(*transferTO);
    }

    //Transfers back from transferTO to transferFROM
    if(transferFROM->isStable() || !transferTO->isStable()) {
      ++g;
      cout << "\nGeneration: " << g << endl;
      if(outFile == "") {
        transferTO->printBoard();
      } else {
        transferTO->printBoard(outFile);
      }

      if(gameOptions == 1) {
        sleep(2);
        transferTO->boardTransfer(*transferFROM);
      } else if(gameOptions == 0) {
        cout << "\nHit enter to progress" << endl;
        cin.get();
        transferTO->boardTransfer(*transferFROM);
      } else {
        transferTO->boardTransfer(*transferFROM);
      }
    } else {
      break;
    }
  }

}

//GenerationD runs the simulation for Class DoughnutGame
void Game::GenerationD(DoughnutGame *transferFROM, DoughnutGame *transferTO) {
    for(int g = 0; !transferFROM->isStable() || !transferTO->isStable(); ++g) {

      //Transfers Grid from transferFROM to transferTO
      cout << "\nGeneration: " << g << endl;
      if(outFile == "") {
        transferFROM->printBoard();
      } else {
        transferFROM->printBoard(outFile);
      }

      if(gameOptions == 1) {
        sleep(2);
        transferFROM->boardTransfer(*transferTO);
      } else if(gameOptions == 0) {
        cout << "\nHit enter to progress" << endl;
        cin.get();
        transferFROM->boardTransfer(*transferTO);
      } else {
        transferFROM->boardTransfer(*transferTO);
      }

      //Transfers back from transferTO to transferFROM
      if(transferFROM->isStable() || !transferTO->isStable()) {
        ++g;
        cout << "\nGeneration: " << g << endl;
        if(outFile == "") {
          transferTO->printBoard();
        } else {
          transferTO->printBoard(outFile);
        }

        if(gameOptions == 1) {
          sleep(2);
          transferTO->boardTransfer(*transferFROM);
        } else if(gameOptions == 0) {
          cout << "\nHit enter to progress" << endl;
          cin.get();
          transferTO->boardTransfer(*transferFROM);
        } else {
          transferTO->boardTransfer(*transferFROM);
        }
      } else {
        break;
      }
    }

}

//Sets up the game based on the user answers.
void Game::runGame() {
  bool temp = true;
  string userInput;
  Grid* board;
  int gamemode;

  cout << "Welcome to the Game of Life" << endl;
  cout << "\nWould you like to input a text file or generate a random board?" << endl;
  cout << "\n1: Textfile\n2: Random" << endl;
  while(temp) {
    cin >> userInput;
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
    if(userInput == "1" || userInput == "text file" || userInput == "textfile") {
      string outFile;
      cout << "Enter name of textfile: " << endl;
      //Generate textfile Grid
      cin >> outFile;
      board = new Grid(outFile);
      temp = false;
    } else if(userInput == "2" || userInput == "random" || userInput == "Random") {
      //Generate Random Grid
      int w, h;
      double d;
      cout << "Enter board width: " << endl;
      cin >> w;
      cout << "Enter board height" << endl;
      cin >> h;
      cout << "Enter popuation density (decimal between 0.1 - 1)" << endl;
      cin >> d;
      temp = false;
      board = new Grid(w, h, d);
    } else {
      cout << "That is not a valid input\n\n1: Textfile\n2: Random" << endl;
    }
  }
  cout << "What game mode would you like to use? " << endl;
  cout << "\n1: Classic Mode\n2: Doughnut Mode\n3: Mirror Mode" << endl;

  temp = true;
  while(temp) {
    cin >> userInput;
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
    if(userInput == "1" || userInput == "classic mode" || userInput == "classicmode") {
      gamemode = 0;
      temp = false;
    } else if(userInput == "2" || userInput == "doughnut mode" || userInput == "doughnutmode") {
      gamemode = 1;
      temp = false;
    } else if(userInput == "3" || userInput == "mirror mode" || userInput == "mirrormode") {
      gamemode = 2;
      temp = false;
    } else {
      cout << "That is not a valid input\n\n1: Classic Mode\n2: Doughnut Mode\n3: Mirror Mode" << endl;
    }
  }
  cout << "Would you like a brief pause between generations or to hit enter before each generation?" << endl;
  cout << "\n1: Pause\n2: Enter\n3: No Pause" << endl;

  temp = true;
  cin >> userInput;
  transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
  if(userInput == "1" || userInput == "pause") {
    cout << "Enter name of textfile: " << endl;
    //implement pause in generation
    gameOptions = 1;
  } else if(userInput == "2" || userInput == "enter") {
    //implement enter in generation
    gameOptions = 2;
  } else {
    //make sure to pass pause and enter in generation
    gameOptions = 0;
  }


  //Checks if the user would like to output to an external file
  cout << "Would you like to output to a text file? (y/n)" << endl;
  temp = true;
  string outfile = "";
  while(temp) {

    cin >> userInput;
    cout << userInput << endl;
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
    if(userInput == "y" || userInput == "yes") {
      cout << "Enter the file you would like to output to: " << endl;
      cin >> outFile;
      temp = false;
    } else if(userInput == "n" || userInput == "no") {
      temp = false;
    } else {
      cout << "That is not a valid input\n\nWould you like to output to a text file? (y/n)" << endl;
    }
  }

  //Runs generation based on class
  if(gamemode == 0) {
    ClassicGame* cg1 = new ClassicGame(board);
    ClassicGame* cg2 = new ClassicGame(board);
    GenerationC(cg1, cg2);
  } else if(gamemode == 1) {
    DoughnutGame* dg1 = new DoughnutGame(board);
    DoughnutGame* dg2 = new DoughnutGame(board);
    GenerationD(dg1, dg2);
  } else if (gamemode == 2) {
    MirrorGame* mg1 = new MirrorGame(board);
    MirrorGame* mg2 = new MirrorGame(board);
    GenerationM(mg1, mg2);
  }
}
