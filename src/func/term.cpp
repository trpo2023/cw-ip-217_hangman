#include <iostream>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#include "term.h"





using namespace std;
void Hidestroks()
{
    termios tty;

    tcgetattr(STDIN_FILENO, &tty);

   
    tty.c_lflag &= ~ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}






void Showstroks()
{
   termios tty;

    tcgetattr(STDIN_FILENO, &tty);

 
    tty.c_lflag |= ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}
