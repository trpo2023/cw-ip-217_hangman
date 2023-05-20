#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


#include "../src/func/game.h"
#include "../src/func/term.h"


#define FILE 563
#define GAME 9

array<string, GAME> stage ={ "",
                                    "        ||                  \n        ||                  \n        ||                  \n        ||                  \n        ||                  \n        ||                  \n        ||                  \n        ||                  \n        ||                  \n        ||                  \n        ||                  \n        ||                  \n        ||                  \n        ||                  \n  ===================    \n",
                                    "====================================             \n       ==||=============================              \n         ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n  ===================                             \n",
                                    "====================================             \n       ==||=============================              \n         ||  /  /                  ||                 \n	 || /  /                                      \n	 ||/  /                                       \n	 ||  /                                        \n	 || /                                         \n	 ||/                                          \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n  ===================                             \n",
                                    "====================================             \n       ==||=============================              \n         ||  /  /                  ||                 \n	 || /  /                ========              \n	 ||/  /                (|.|  |.|)             \n	 ||  /                  ||____||              \n	 || /                                         \n	 ||/                                          \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n  ===================                             \n",
                                    "====================================             \n       ==||=============================              \n         ||  /  /                  ||                 \n	 || /  /                ========              \n	 ||/  /                (|.|  |.|)             \n	 ||  /                  ||____||              \n	 || /                  ||      ||             \n	 ||/                  ||        ||            \n	 ||                    ||      ||             \n	 ||                     ||===||               \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n  ===================                             \n",
                                    "====================================             \n       ==||=============================              \n         ||  /  /                  ||                 \n	 || /  /                ========              \n	 ||/  /                (|.|  |.|)             \n	 ||  /                  ||____||              \n	 || /                  ||      |||||          \n	 ||/                  ||        || ||         \n	 ||                    ||      ||   ||        \n	 ||                     ||===||               \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n  ===================                             \n",
                                    //"_______\n|/    |\n|     O\n|    /|\n|\n|\n|______\n",
                                    "====================================             \n       ==||=============================              \n         ||  /  /                  ||                 \n	 || /  /                ========              \n	 ||/  /                (|.|  |.|)             \n	 ||  /                  ||____||              \n	 || /               |||||      |||||          \n	 ||/               || ||        || ||         \n	 ||               ||   ||      ||   ||        \n	 ||                     ||===||               \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n  ===================                             \n",
                                    //"_______\n|/    |\n|     O\n|    /|\\\n|    /\n|\n|_______\n",
                                    "====================================             \n       ==||=============================              \n         ||  /  /                  ||                 \n	 || /  /                ========              \n	 ||/  /                (|.|  |.|)             \n	 ||  /                  ||____||              \n	 || /               |||||      |||||          \n	 ||/               || ||        || ||         \n	 ||               ||   ||      ||   ||        \n	 ||                     ||===||               \n	 ||                     ||===||               \n	 ||                    ||     ||              \n	 ||                 __==      ==__            \n	 ||                                           \n	 ||                                           \n	 ||                                           \n  ===================                             \n"                                  };
Shell::Shell() {
  _quit = false;
  _p1._score = 0;
  _p1._name = "Player 1";
  _p1.guess = true;
  _p2._score = 0;
  _p2._name = "Player 2";
  guess = _p1;
  word = _p2;
}







void Shell::init() {
  int options = 3;
  int choose;

  cout <<   "\n==Hangman==\n\nSelect an option:" <<
            "\n1.Single Player" <<
            "\n2.Multiplayer" <<
            "\n3.Exit" << endl;
  cin >> choose;
  option(choose);

  if (choose < 1 || choose > options) {
    cout << "\nPlease select a valid input option!" << endl;
    init();
  }
  else if (choose == options) {
    cout << "Exiting..." << endl;
    _quit = true;
    return;
  }
}







void Shell::run() {

  _attempts = 0;
  Data session;
  if (!_multiplayer) {
      session.gen();
  }
  else {
    session.addWord(guess, word);
  }
  while (_attempts < GAME - 1) {
    session.display();
    if (!session.Guess()) {
      _attempts++;
      cout << endl << stage.at(_attempts) << endl << endl;
    }
    if (session.end()) {
      cout << "\nCongratulations " << guess._name << "you won!" << endl;
      guess._score ++;
      break;
    }
  }
  if (!session.end()) {
    cout << "\nGAME OVER " << guess._name << "you lose!" << endl;
    word._score ++;
  }
  session.Ans();

  if (_multiplayer) {
    Switch();
  }
  Score();
}







void Shell::option(int choice) {
  switch(choice) {
    case 1 :
      cout << "\nSelected PC opponent!" << endl;
      _multiplayer = false;  word._score = 0;
      _p2._act = false;
      word._act = false;
      break;
    case 2 :
      cout << "\nSelected player opponent!" << endl;
      _multiplayer = true;
      _p2._act = true;
      break;
    case 3:
      break;
    default :
      throw "\nUnrecognised input... Congrats, you broke it.\n";
  }
}


void Shell::Switch() {
  if (_p1.guess == true) {

    _p1._score += guess._score;
    _p2._score += word._score;

    _p1.guess = false;
    _p2.guess = true;
    guess = _p1;
    word = _p2;
  }
  else {
    _p2._score += guess._score;
    _p1._score += word._score;
    _p2.guess = false;
    _p1.guess = true;
    guess = _p2;
    word = _p1;
  }
  guess._score = 0;
  word._score = 0;
}






void Shell::Score() {
  cout << endl << _p1._name << ": " << _p1._score << endl;
  if (_p2._act) {
    cout << endl << _p2._name << ": " << _p2._score << endl;
  }
}

Data::Data() {
  Sol = "";
}


void Data::gen() {
  int ran = rand() % FILE;
  int Num = 0;
  string line;
  ifstream wordList("../src/func/words.txt");
  while(getline(wordList, line)) {
    ++Num;
    if (Num == ran) {
      word = line;
    }
  }
  Sol.append(word.size(), '.');
}


void Data::addWord(Player guess, Player wordf) {
  Hidestroks();
  cout << "\n"  << wordf._name << "Please provide a word for " << guess._name << " to guess:";
  cin >> word;
  Showstroks();
  Sol.append(word.size(), '.');
}


void Data::display() {
  cout << endl;
  cout << Sol << endl;
  cout << "\nIncorrect guesses: " << incorrect.size() << endl;
  for (unsigned int i = 0; i < incorrect.size(); i++) {
      cout << incorrect.at(i) <<", ";
  }
  cout << endl;
  return;
}


void Data::Ans() {
  cout << "\nThe correct answer was: \n" << word << endl;
}


bool Data::Guess() {
  cout << "\n\nPlease guess a letter (Only the first player provided will be read):" << endl;
  cin >> guess;
  bool ans = false;
  for (unsigned int i = 0; i < incorrect.size(); i++) {
    if (guess == incorrect.at(i)) {
      cout << "\nYou've already guessed that letter!" << endl;
      ans = true;
    }
  }
  for (unsigned int i = 0; i < Sol.size(); i++) {
    if (guess == Sol.at(i)) {
      cout << "\nYou've already guessed that letter!" << endl;
      ans = true;
    }
    else if (guess == word.at(i)) {
      Sol.at(i) = guess;
      ans = true;
    }
  }
  if (!ans) {
    incorrect.push_back(guess);
  }
  return ans;
}


bool Data::end() {
  if (Sol == word) {
    return true;
  }
  else {
    return false;
  }
}
