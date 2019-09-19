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

int main(void)
{

	WINDOW* main_window = nullptr;
	int num_cols = 0;
	int num_rows = 0;

	/*
	SETUP
	*/
	
	//START NEW TEXT FILE
	ifstream fin;
	fin.open("myFile.txt");

	//USE FILE CODE HERE

	fin.close();

	//initialize window
	main_window = initscr();

	//resize our window
	//resize_term(5000, 5000); //work on the resize here
	getmaxyx(main_window, num_rows, num_cols);
	//resize_term(num_rows - 1, num_cols - 1);//work on resize here

	//turn keyboard echo
	noecho();

	keypad(main_window, TRUE);

	//hide cursor
	curs_set(TRUE);

	//SET BORDER COLOR
	//attron(COLOR_PAIR(2));
	//start_color();
	//init_pair(2, COLOR_YELLOW, COLOR_YELLOW);
	//attroff(COLOR_PAIR(2));
	//color_set(1, main_window);
	//wcolor_set(main_window, COLOR_GREEN, main_window);

	/*
	MAIN PROGRAM LOGIC
	*/

	//ROWS MANIPULATION
	for (int i = 0; i < num_cols; i++)
	{
		//top row
		
		start_color();
		init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
		
		attron(COLOR_PAIR(1));
		mvaddch(0, i, ACS_BLOCK);
		attroff(COLOR_PAIR(1));
		//bottom row
		mvaddch(num_rows - 1, i, ACS_BLOCK);
	}
	
	// TEXT EDITOR NAME, VERSION, and FILE NAME
	char txtName[20] = "My Micro 1";
	char fileName[20] = "File: ";
	start_color();
	init_pair(2, COLOR_BLACK, COLOR_WHITE);

	attron(COLOR_PAIR(2));
	mvprintw(0, 5, txtName);
	mvprintw(0, 50, fileName);
	attroff(COLOR_PAIR(2));

	//COLUMNS MANIPULATION
	for (int i = 0; i < num_rows; i++)
	{
		//left column
		mvaddch(i, 0, ACS_BLOCK);
		//right column
		mvaddch(i, num_cols - 1, ACS_BLOCK);
	}

	/*
	GUI FILE TEXT here
	*/

	attron(COLOR_PAIR(2));
	//mvprintw(27, 1, "^G Get Help    ^O WriteOut     ^R Read File    ^Y Prev Page    ^K Cut Text     ^C Cur Pos");
	//mvprintw(28, 1, "^X Exit        ^J Justify      ^W Where is     ^V Next Page    ^U UnCut Text   ^T To Spell");
	mvprintw(29, 1, "^F: FILE	^E: EDIT	^V: VIEW	^H: HELP");
    attroff(COLOR_PAIR(2));

	/*
	INPUT CODE HERE
	*/

	//creating a NEW WINDOW for input
	//WINDOW* inputwin = newwin(3, 12, 5, 5);
	//box(inputwin, 0, 0);
	//refresh();
	//wrefresh(inputwin);

	//keypad(inputwin, true);

	//HOW TO CREATE NEW, etc
	int inChar = wgetch(main_window);
		
		//switch for input
		switch (inChar)
		{
		case KEY_UP: mvwprintw(main_window, 1, 1, "You pressed up!"), wrefresh(main_window);
			break;
		case KEY_DOWN: mvwprintw(main_window, 1, 1, "You pressed down!"), wrefresh(main_window);
			break;
		case KEY_RIGHT: mvwprintw(main_window, 1, 1, "You pressed right!"), wrefresh(main_window);
			break;
		case KEY_LEFT: mvwprintw(main_window, 1, 1, "You pressed left!"), wrefresh(main_window);
			break;
		};

	getch();

	//INPUT CODE HERE
	//get user input
	//pause for input

	//char input = getch();
	//char userStr[100];
	//getstr(userStr);
	//mvprintw(2, 2, userStr);

	//int input = getch();

	/*
	END CURSES MODE
	*/
	endwin();

	return 0;
}