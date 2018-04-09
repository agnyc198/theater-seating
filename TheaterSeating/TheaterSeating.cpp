// TheaterSeating.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

#include "sqlite3.h"

#include "Menu.h"
#include "Theater.h"


int main()
{
	// Constant variables
	const int seats = 9;
	const int rows = 10;

	bool keep_going = true;

	// Test sqlite3
	sqlite3 *db;
	char *zErrMsg = nullptr;
	int rc = 0;

	rc = sqlite3_open("test.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't Open Database!\n");
		return(0);
	}
	else
	{
		fprintf(stderr, "Opened Database Successfully\n");
	}


	// Create theater
	Theater theater = Theater(seats, rows);

	// Create Menu
	Menu menu = Menu();
	
	while (keep_going)
	{
		menu.GetUserChoice();
		system("cls");
		switch (menu.GetMenuChoice())
		{
			case Menu::MenuOptions::kShowSeating:
			{
				theater.DisplaySeating();
				break;
			}
			case Menu::MenuOptions::kSellSeats:
			{
				// TODO: Sell Seats
				puts("Comming Soon!");
				break;
			}
			case Menu::MenuOptions::kStats:
			{
				// TODO: Show stats
				puts("Comming Soon!");
				break;
			}
			case Menu::MenuOptions::kExit:
			{
				puts("Exiting...");
				puts("Please Come Again Soon!");
				keep_going = false;
				break;
			}
		}
	}

    return 0;
}
