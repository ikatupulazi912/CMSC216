#include <stdio.h>

void main()
{
	char* a[] = { "dog", "food" };
	char* tmp[3];

	int i;
	for (i = 0; i < 2; i++)
	{
		tmp[i] = a[i];
	
	}
	tmp[2] = "oga";
	a = tmp;
	
	
	printf("%s", a[2]);
	
}
