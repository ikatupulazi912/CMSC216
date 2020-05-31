#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 20


queue_type* queue_new(void)
{
	
	queue_type *queue = (queue_type *)malloc(sizeof(queue_type));
	queue->size = 0;
	queue->end = -1;

	queue->array = (char*)malloc(0);

	return  queue;;
}

int queue_enqueue(queue_type* p1, char x)
{
	if (p1->size == MAX)
	{
		printf("QueueUnderflow - The queue is full");
		return -1;
	}
	
	
		 
                
               ((*p1).size)++;
		((*p1).end)++;

                p1->array = (char*)realloc(p1->array, p1->size);
                p1->array[p1->end] = x;

	return 0;

}

int queue_length(queue_type* p1)
{
	return p1->size;
}

char queue_dequeue(queue_type* p1)
{
	int size = p1->size--;
	char Rchar = p1->array[0];
	char* tempA = (char*)malloc(size);


	int x;
	for (x = 0; x < size; x++)
	{
		tempA[x] = p1->array[x + 1];
	}

	p1->array = tempA;

	return Rchar;

}

char queue_front(queue_type* p1)
{
	return *(p1->array);
}

void queue_delete(queue_type* p1)
{
	free(p1);
}




