#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void buildTree(int);

int main()
{
	int height;
	printf("Enter a height: ");
	scanf("%d", &height);

	buildTree(height);
	return 0;
}

void buildTree(int height)
{
	int fCount = 1;
	
	for (; fCount <= height; fCount++)
	{
		
		char* leftTri = malloc(100);
		char* rightTri = malloc(100);
		strcat(rightTri, "  ");
		int numOfHashes = fCount * 2;
		int sCount;
		for (sCount = 1; sCount <= numOfHashes; sCount++)
		{
			if (sCount <= (numOfHashes/2))
			{
				strcat(leftTri, "#");
				continue;
			}	
			
			
			strcat(rightTri, "#");

		}

		
		printf("%50s", leftTri);
		printf("%s", rightTri);
		printf("\n");
		free(leftTri);
	/*	free(rightTri);*/
	}
}
