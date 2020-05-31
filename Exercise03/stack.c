#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

stack_type* stack_new(void)
{
	stack_type *stack = (stack_type*)malloc(sizeof(stack_type));
			
	stack->size = 0;
	stack->array = (char*)malloc(0);
	
	return stack;
}

int stack_push(stack_type* p1, char x)
{
	if (p1->size == MAX)
	{
		printf("StackUnderflow - The stack is full");
		return -1;
	}
	
	p1->size++;
	p1->array = (char*)realloc(p1->array, p1->size);
	
	p1->array[p1->size - 1] = x;

	return 0;

		
}

int stack_height(stack_type* p1)
{
	return p1->size;
}

char stack_pop(stack_type* p1)
{
	char Rchar = p1->array[p1->size - 1];
	int size = p1->size--;
	char* Narray = (char*)malloc(size);
	int x;
	for (x = 0; x < size; x++)
	{
		Narray[x] = p1->array[x];
	}

	p1->array = Narray;

	return Rchar;
}

char stack_top(stack_type* p1)
{
	return p1->array[p1->size - 1];
}

void stack_delete(stack_type* p1)
{
	free(p1);
}
