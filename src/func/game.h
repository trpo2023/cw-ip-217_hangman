#include <string>
#include <stdio.h>

using namespace std;



void Hidestroks();
void Showstroks();



class Player {
  public:
    int _score;
    bool guess;
    bool _act;
    string _name;
};






class Shell {
  public:
    Shell();
    void init();
    void run();
    void option(char choice);
    void Switch();
    void Score();
    bool _quit;
    int _games;
    Player _p1;
    Player _p2;
    Player guess;
    Player word;
    bool _multiplayer;
  private:
    int _attempts;
};






class Data {
  public:
    Data();
    void gen();
    void addWord(Player guess, Player word);
    void display();
    void Ans();
    bool Guess();
    bool end();
    char guess;
    string incorrect;
    string Sol;
    string word;

    bool multiplayer;
    
};
