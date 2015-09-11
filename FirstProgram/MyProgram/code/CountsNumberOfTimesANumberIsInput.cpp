#include <iostream>
#include <conio.h>
int main()
{
	int curval = 0, val = 0;
	if(std::cin >> curval)
	{
		int cnt = 1;
		while(std::cin >> val)
		{
			if(val == curval)
				++cnt;
			else
			{
				std::cout << curval << " occurs " << cnt << " times" << std::endl;
				curval = val;
				cnt = 1;
			}
		}
		std::cout << curval << " occurs " << cnt << " times" << std::endl;



	}

	getch();
	return 0;
}