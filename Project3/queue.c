#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include "CMSC216_bst.h"



struct BST_type
{
    char* data;
    int level;
    bst* left;
    bst* right;
};

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

int queue_enqueue(queue_type* p1, bst *x)
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

bst* queue_dequeue(queue_type* p1)
{
    int f;
    int b;
   
    
    bst* value = p1->array[0];
   
    for (f = 0, b = 1; b < p1->size; b++, f++)
    {
   
        p1->array[f] = p1->array[b];
    }

   
    p1->array[p1->size - 1] = NULL;
   
    (p1->size)--;
    (p1->end)--;
    return value;


}

bst* queue_front(queue_type* p1)
{
    return p1->array[0];
}

void queue_delete(queue_type* p1)
{
    free(p1);
}

