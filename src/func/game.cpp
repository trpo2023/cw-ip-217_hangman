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
                                    "====================================             \n       ==||=============================              \n         ||  /  /                  ||                 \n	 || /  /                ========              \n	 ||/  /                (|.|  |.|)             \n	 ||  /                  ||____||              \n	 || /               |||||      |||||          \n	 ||/               || ||        || ||         \n	 ||               ||   ||      ||   ||        \n	 ||                     ||===||               \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n	 ||                                           \n  ===================                             \n",
                                    "====================================             \n       ==||=============================              \n         ||  /  /                  ||                 \n	 || /  /                ========              \n	 ||/  /                (|.|  |.|)             \n	 ||  /                  ||____||              \n	 || /               |||||      |||||          \n	 ||/               || ||        || ||         \n	 ||               ||   ||      ||   ||        \n	 ||                     ||===||               \n	 ||                     ||===||               \n	 ||                    ||     ||              \n	 ||                 __==      ==__            \n	 ||                                           \n	 ||                                           \n	 ||                                           \n  ===================                             \n"                                  };
Shell::Shell() {
  _quit = false;
  _p1._score = 0;
  _p1._name = "Игрок 1";
  _p1.guess = true;
  _p2._score = 0;
  _p2._name = "Игрок 2";
  guess = _p1;
  word = _p2;
}







void Shell::init() {
  char options = '3';
  char choose = '5';

  cout <<   "\n ________________________________\n|____________Виселица____________|\n|______Выберите режим игры:______|" <<
            "\n|      1. Один игрок(VsPC)       |" <<
            "\n|      2. Два игрока             |" <<
            "\n|      3. Выход                  |" <<
            "\n|________________________________|" << endl;

  for(;choose < '1' || choose > '3';) {
    cin >> choose;
    if (choose < '1' || choose > '3') {
      cout << "\nНеправильный ввод. Выберите цифру(1-3)..." << endl;
    }
    else if (choose == options) {
      _quit = true;
      return;
    }
  }
  option(choose);
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
      cout << "\n!!!!!!!!!! " << guess._name << " Победа!" << endl;
      guess._score ++;
      break;
    }
  }
  if (!session.end()) {
    cout << "\nИгра закончена. " << guess._name << " Поражение." << endl;
    word._score ++;
  }
  session.Ans();

  if (_multiplayer) {
    Switch();
  }
  Score();
}







void Shell::option(char choice) {
  switch(choice) {
    case '1' :
      cout << "\nВыбран соперник-компьютер." << endl;
      _multiplayer = false;  word._score = 0;
      _p2._act = false;
      word._act = false;
      break;
    case '2' :
      cout << "\nВыбрана игра на двух игроков!" << endl;
      _multiplayer = true;
      _p2._act = true;
      break;
    case '3':
      break;
    default :
      throw "\nНераспознанный ввод... \nОшибка...\n";
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
  Sol.append(word.size(), '#');
}


void Data::addWord(Player guess, Player wordf) {
  Hidestroks();
  cout << "\n"  << wordf._name << "Введите слово для" << guess._name << " Угадайте:";
  cin >> word;
  Showstroks();
  Sol.append(word.size(), '.');
}


void Data::display() {
  cout << endl;
  cout << Sol << endl;
  cout << "\nОшибки: " << incorrect.size() << endl;
  for (unsigned int i = 0; i < incorrect.size(); i++) {
      cout << incorrect.at(i) <<", ";
  }
  cout << endl;
  return;
}


void Data::Ans() {
  cout << "\nВаше слово: \n" << word << endl;
}


bool Data::Guess() {
  cout << "\n\nУгадайте букву:" << endl;
  cin >> guess;
  bool ans = false;
  for (unsigned int i = 0; i < incorrect.size(); i++) {
    if (guess == incorrect.at(i)) {
      cout << "\nЭта буква уже использована." << endl;
      ans = true;
    }
  }
  for (unsigned int i = 0; i < Sol.size(); i++) {
    if (guess == Sol.at(i)) {
      cout << "\nЭта буква уже угадана." << endl;
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
