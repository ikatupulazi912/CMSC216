#include "GQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct edge Edge;
typedef struct vertex Vertex;


queue_type* queue_new(void)
{
    queue_type* queue;
    queue = (queue_type*)malloc(sizeof(queue_type));
    if (queue != NULL)
    {
        queue->size = 0;
        queue->end = -1;

    }
    else
    {
        return;
    }


    return  queue;
}

int queue_enqueue(queue_type* p1, int x)
{


    int size = ++(p1->size);
    int end = ++(p1->end);
    (p1->array)[end] = x;
    p1->size = size;

    return 1;

}

int queue_length(queue_type* p1)
{
    return p1->size;
}

int queue_dequeue(queue_type* p1)
{
    int f;
    int b;

    int value = p1->array[0];

    for (f = 0, b = 1; b < p1->size; b++, f++)
    {

        p1->array[f] = p1->array[b];
    }


    p1->array[p1->size - 1] = 0;

    (p1->size)--;
    (p1->end)--;
    return value;


}

int queue_front(queue_type* p1)
{
    return p1->array[0];
}

int contains(queue_type* p1, int t)
{
    int x;
    for (x = 0; x < p1->size; x++)
    {
        if (p1->array[x] == t)
        {
            return 1;
        }
    }

    return -1;
}

int randomVal(queue_type* p1)
{
    time_t a;
    srand((unsigned)time(&a));
    return p1->array[rand() % p1->size];
}

void queue_delete(queue_type* p1)
{
    free(p1);
}

