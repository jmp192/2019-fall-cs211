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
	resize_term(num_rows - 1, num_cols - 1);
	//getmaxyx(main_window, num_rows, num_cols);

	//turn keyboard echo
	noecho();

	keypad(main_window, TRUE);

	//hide cursor
	curs_set(FALSE);

	//main program logic goes here
	for (int i = 0; i < num_cols; i++)
	{
		//top row
		mvaddch(0, i, ACS_BOARD);
		//bottowm row
		mvaddch(num_rows - 1, i, ACS_BOARD);
	}

	for (int i = 0; i < num_rows; i++)
	{
		//left column
		mvaddch(i, 0, ACS_BOARD);
		//right column
		mvaddch(i, num_cols - 1, ACS_BOARD);

	}
	//pause for input
	char input = getch();

	//end curses mode
	endwin();

	return 0;
}