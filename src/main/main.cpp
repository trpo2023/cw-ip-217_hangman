#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;


#include "../src/lib/game.h"
#include "../src/lib/term.h"





///////////////////////////////////////
int main() {
  char restart;
  srand (time(NULL));
  Shell game;
  for (;;) {
    game.init();
    if (game._quit == true) {
      break;
    }
    for (;;) {
      game.run();
   
      cout << "Play again? yes / no";
      cin >> restart;
      if(restart != 'yes') {
        break;
      }
    }
  }
  return 0;
}
