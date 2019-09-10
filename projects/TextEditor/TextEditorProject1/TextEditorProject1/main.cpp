#define PDC_DLL_BUILD 1
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "curses.h"
#include "curspriv.h"
#include "panel.h"
using namespace std;

//CONSTANTS
const int SET_WIDTH = 15; // Width of GUI text

int main(void)
{

	WINDOW* main_window = nullptr;
	int num_cols = 0;
	int num_rows = 0;

	//SETUP
	//initialize window
	main_window = initscr();

	//resize our window
	//resize_term(5000, 5000);
	getmaxyx(main_window, num_rows, num_cols);
	//resize_term(num_rows - 1, num_cols - 1);

	//turn keyboard echo
	noecho();

	keypad(main_window, TRUE);

	//add text while running
	//char text[100];
	//getstr(text);

	//hide cursor
	curs_set(FALSE);

	//set text & window color
	//init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_GREEN);
	//color_set(COLOR_GREEN, main_window);
	//wcolor_set(main_window, COLOR_GREEN, main_window);

	//MAIN PROGRAM LOGIC GOES HERE

	//ROWS MANIPULATION
	for (int i = 0; i < num_cols; i++)
	{
		//top row
		mvaddch(0, i, ACS_BLOCK);
		//bottom row
		mvaddch(num_rows - 1, i, ACS_BLOCK);
	}

	// text editor name, version, and file name
	attron(A_REVERSE);
	mvprintw(0, 5, "My Micro 1");
	mvprintw(0, 50, "File: ");
	attroff(A_REVERSE);
	//printw("this is some text");

	//COLUMNS MANIPULATION
	for (int i = 0; i < num_rows; i++)
	{
		//left column
		mvaddch(i, 0, ACS_BLOCK);
		//right column
		mvaddch(i, num_cols - 1, ACS_BLOCK);
	}

	//file gui
	//attron(A_REVERSE);
	mvprintw(27, 1, "^G Get Help    ^O WriteOut     ^R Read File    ^Y Prev Page    ^K Cut Text     ^C Cur Pos");
	mvprintw(28, 1, "^X Exit        ^J Justify      ^W Where is     ^V Next Page    ^U UnCut Text   ^T To Spell");
    //attroff(A_REVERSE);

	//pause for input
	char input = getch();

	//end curses mode
	endwin();

	return 0;
}