#define PDC_DLL_BUILD 1
#include "curses.h"
#include <string>
using namespace std;

int main(void)
{
	WINDOW* main_window = nullptr;
	int num_rows = 0;
	int num_cols = 0;

	//intialize screen, being curses mode
	main_window = initscr();

	//take up most of the screen
	getmaxyx(main_window, num_rows, num_cols);
	resize_term(num_rows - 1, num_cols - 1);
	getmaxyx(main_window, num_rows, num_cols);

	//turn off key echo
	noecho();
	//nodelay(main_window, TRUE);
	keypad(main_window, TRUE);
	curs_set(0);

	//FUN STUFF HAPPENS HERE
	for (int i = 0; i < num_cols; i++)
	{
		//top border
		mvaddch(0, i, ACS_CKBOARD);

		//bottom border
		mvaddch(num_rows - 1, i, ACS_CKBOARD);
	}
	for (int i = 0; i < num_rows; i++)
	{
		//left column
		mvaddch(i, 0, ACS_CKBOARD);

		//right column
		mvaddch(i, num_cols - 1, ACS_CKBOARD);
	}


	//tells curses to draw
	refresh();

	//revert back to normal console mode
	nodelay(main_window, TRUE);
	keypad(main_window, TRUE);
	mvaddstr(0, 0, "Press any key to continue...");
	char result = getch();
	endwin();

}