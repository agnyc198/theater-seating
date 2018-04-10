// TheaterSeating.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>

#include "Menu.h"
#include "Theater.h"


// Prototypes
void SellSeats();


int main()
{
	// Constant variables
	const int seats = 9;
	const int rows = 10;

	bool keep_going = true;

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
				SellSeats();
				theater.DisplaySeating(2, 2, 5);
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


//
// Sell Seats
void SellSeats()
{
	puts("Coming Soon!");
}