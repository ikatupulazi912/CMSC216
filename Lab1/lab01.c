#include <stdio.h>

int main()
{
	
	int i = 1;
	int x;
	int tempX = 0;
	int y = 1;
	int count = 0;

	for(x = 1; x <= 19; x++)
	{
		tempX = x;
		for(y = 1; y<=x ; y++)
		{
			if(x <= 10)
			{
				printf("%2d ", i);
				i++;
			}
			else
			{
				if((tempX - 10) > 0)
				{
					printf("   ");
					count++;
					tempX--;
				}
				else if((tempX - 10) == 0)
				{
					tempX--;
					count++;
					continue;
				}
				else
				{
					count++;
					printf("%2d ", i);
					i++;
				}
					
					
				if(count == 11)
				{
					break;
				}
			}
		}
		printf("\n");
		count = 0;
	}
	return 0;
}
