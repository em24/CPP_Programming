#include <iostream>
#include <conio.h>
#include "Sales_item.h"
int main()
{
	Sales_item total;
	if(std::cin >> total)
	{
		int count = 1;
		Sales_item trans;
		while(std::cin >> trans)
		{
			if(total.isbn() == trans.isbn())
			{
				total += trans;
				count++;
			}
			else
			{
				std::cout << std::endl << "Book totals:" << std::endl
					<< total << std::endl
					<< count << " transactions with this book" << std::endl;
				count = 1;
				total = trans;
			}
		}
		std::cout << std::endl << "Book totals:" << std::endl
			<< total << std::endl
			<< count << " transactions with this book" << std::endl;
	}
	else
	{
		std::cout << "No data" << std::endl;
		return -1;
	}
	
	

	getch();
	return 0;
}