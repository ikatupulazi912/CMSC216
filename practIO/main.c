#include <stdio.h>
#include <stdlib.h>

struct p
{
	int x;
	int y;
		


};


int main(int c, char *v[])
{
	struct p dog = {2 , 3};
	int *p = (int *) malloc(100);	
	printf("%d\n", sizeof(dog));	
	printf("%d\n", sizeof(&p));
	return 0;
}

