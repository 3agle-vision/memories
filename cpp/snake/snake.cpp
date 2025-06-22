/*
Dated: 12/22/2019
Title: Snake
For: School Project
made by: ə'sassin
*/

#include<windows.h>
#include<iostream>
#include<conio.h>
#include<dos.h>
#include<string>
#include<process.h>
#include<time.h>

using namespace std;
void board();

void gotoxy(short x, short y) {
  COORD c = {
    x,
    y
  };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main() {
  string name;
  system("cls");
  cout << "\n\n\n\n";
  cout << "\t---------------------------------------------\n";
  cout << "\t   Hi, Welcome to the Classical Snake game\n";
  cout << "\n";
  cout << "\t---------------------------------------------\n";
  gotoxy(15, 6);
  cout << "\t  Enter your name:";
  cin >> name;
  system("cls");
  cout << "\n\n\n\n\t\t If you want to pause the game press any \n\t\t key other than  W,A,S,D \n\n\t\t PRESS ANY KEY TO CONTINUE";
  getch();
  int a = 2, b = 2, t = 120, n, x, y;
  char jump, c = '0', ch = '*'; //c=4 i.e) 4th ASCII character that is a diamond
  system("cls");
  board();
  int score = -1; //-1 so that initial score = 0
  gotoxy(a, b);
  cout << ch;
  jump = getch();
  position:
    x = rand() % 77 + 3;
  y = rand() % 22 + 3; //this determines the position of food to be eaten
  ++score; //for score 
  do {
    while (!kbhit()) {
      system("cls");
      //sound(random(500)); 
      board();
      gotoxy(0, 25);
      cout << name << " your SCORE is: " << score << " \nIf you want to exit press 0.";
      gotoxy(a, b); //to create movement of ch 
      cout << ch;
      gotoxy(x, y); //for position of food
      cout << c;
      if ((a == 1 && (b >= 1 && b <= 25)) || (a == 80 && (b >= 1 && b <= 24)) || (b == 1 && (a >= 1 && a <= 80)) || (b == 24 && (a >= 1 && a <= 80)))
        goto end; //Condition so that user should be out if he hits the wall. /*-------Movement of cursor--------------*/
      if (jump == 72 || jump == 'w' || jump == 'W') --b; //move turtle up
      else if (jump == 80 || jump == 's' || jump == 'S') ++b; //move turtle down
      else if (jump == 77 || jump == 'd' || jump == 'D') ++a; //move turtle right
      else if (jump == 75 || jump == 'a' || jump == 'A') --a; //move turtle left
      else if (jump == '0') goto end;
      if (a == x && b == y)
        goto position; //if turtle feeds the food must get on new position
      Sleep(t);
    }
    jump = getch();
  } while (jump != '0');

  end: gotoxy(35, 12);
  system("cls");
  cout << "\n\n\n\t\t GAME OVER, " << name << " your SCORE is : " << score;
  getch();
  system("cls");
  return 0;
}

void board() {
  cout << "+-------------------------------------------------------------------------------+\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "|                                                                               |\n";
  cout << "+-------------------------------------------------------------------------------+\n";
}
