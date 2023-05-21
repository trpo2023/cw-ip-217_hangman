#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;


#include "../src/func/game.h"
#include "../src/func/term.h"





///////////////////////////////////////
int main() {
  char restart;
  setlocale(LC_ALL, "Russian");
  srand (time(NULL));
  Shell game;
  for (;;) {
    game.init();
    if (game._quit == true) {
      break;
    }
    for (;;) {
      game.run();
      cout << "Играть снова? 1(yes) / 0(no)";
      cin >> restart;
      if(restart != '1') {
        break;
      }
    }
  }
  return 0;
}
