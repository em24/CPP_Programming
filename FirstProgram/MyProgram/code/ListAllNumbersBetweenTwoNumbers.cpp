#include <iostream>
#include <conio.h>
int main()
{
	int v1 = 0, v2 = 0, val = 0;
	std::cin >> v1 >> v2 ;

		val = v1;

		if(val >= v2)
		{
			while(val >= v2)
			{

				std::cout << val << std::endl;
				--val;
			}
		}
		else
		{
			while(val <= v2)
			{

				std::cout << val << std::endl;
				++val;
			}

		}
	


	getch();
	return 0;
}