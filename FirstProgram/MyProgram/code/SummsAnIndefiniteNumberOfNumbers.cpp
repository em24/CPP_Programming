#include <iostream>
#include <conio.h>
int main()
{
	int sum = 0, value = 0;
	while(std::cin >> value)
		sum += value;
	std::cout << sum << std::endl;



	getch();
	return 0;
}