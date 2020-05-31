#include <stdio.h>
#include "graph.h"
#include "GQueue.h"
#include <stdlib.h>

queue_type* queue;

/*Creates a node vertex and initializes the members of the structure*/
int createGraph(Vertex** head)
{
	*head = (Vertex*)malloc(sizeof(Vertex));
	if (*head == NULL)
	{
		return -1;
	}
	(*head)->value = -500;
	(*head)->head = NULL;
	(*head)->next = NULL;
	(*head)->numE = 0;
	return 1;
}

/*Creates vertex and adds it to the linkedlist
 * returns pointer to the linkedlist
 */
Vertex* addVertex(Vertex** head, int value)
{
	if ((*head)->value == -500)
	{
		(*head)->value = value;

		
		return *head;
	}
	else if (searchVertex(head, value) != NULL)
	{
		return *head;
	}

	Vertex* newNode;
	createGraph(&newNode);
	newNode->value = value;
	newNode->next = *head;
	head = &newNode;
	
	

	return *head;
}

/* Creates an edge and adds the edge to the linkedlist of edges within a
 * specific vertex node
 * returns a pointer to the new head of the vertex linkedlist
 */
Vertex* addEdge(Vertex** head, int vertex, int edge)
{
	
	Vertex* CV = searchVertex(head, vertex);
	
	if (CV == NULL)
	{
		
		return NULL;
	}
	else if (searchEdge(&CV, edge) != NULL)
	{
		return *head;
	}
	else
	{
		if (CV->head == NULL)
		{

			CV->head = (Edge*)malloc(sizeof(Edge));
			(CV->head)->dest = edge;
			(CV->head)->next = NULL;
			(CV->numE)++;
			
		}
		else
		{
			Edge* tmp = (Edge*)malloc(sizeof(Edge));
			tmp->dest = edge;
			tmp->next = (CV->head);
			CV->head = tmp;
			(CV->numE)++;
		}
		
		
	}

	if (searchVertex(head, edge) == NULL)
	{

		*head = addVertex(head, edge);
		
	}
	
	return *head;
}

/* Searches the linkedlist of vertices for the specified vertex 
 * returns a pointer to the new head of the pointer linkedlist
 */
Vertex* searchVertex(Vertex** head, int value)
{
	Vertex* v;
	
	for (v = *head; v != NULL; v = v->next)
	{
		
		if (v->value == value)
		{
			return v;
		}
	}

	return NULL;
}

/* searches the linkedlist of edges for the specified edge destination
 * returns a pointer to the specified edge
 */
Edge* searchEdge(Vertex** CV, int dest)
{
	Edge* e;
	for (e = (*CV)->head; e != NULL; e = e->next)
	{
		if (e->dest == dest)
		{
			return e;
		}
	}

	return NULL;
}

/* Determines the distance between two vertices 
 * returns the distance between the two specified vertieces 
 */
int check(Vertex** head, int hunt, int wump)
{
	int dist = 0;
	if (hunt == wump)
	{
		return dist;
	}

	dist++;
	queue = queue_new();

	

	Vertex* CV = searchVertex(head, wump);
	
	queue_type *visited = queue_new();
	int first;
	int x = 0;
	int NowGo = 0;
	
	do {
	
		if (NowGo >= 1)
		{
			CV = searchVertex(head, queue_dequeue(queue));
		
			if (first == (CV->value))
			{
				x = 0;
				dist++;
			}
		}

		Edge* tmp;
		if (contains(visited, CV->value) == 1)
		{
			continue;
		}

		for (tmp = CV->head; tmp != NULL; tmp = tmp->next, x++)
		{
			if (x == 0)
			{
				first = tmp->dest;
				
			}
			
			if (tmp->dest == hunt)
			{
				
				return dist;
			}

			queue_enqueue(queue, tmp->dest);
		}

		queue_enqueue(visited, CV->value);
		NowGo++;
		

	} while (queue_length(queue) != 0);

	return 100000;
}

/*Frees the memory space of the linked list of vertices*/
int freeVertices(Vertex** head)
{
	if (*head == NULL)
	{
		return 1;
	}

	freeVertices(&((*head)->next));
	
	freeEdges(&((*head)->head));

	free(*head);
	return 1;
}

/*Frees the memory space of the linked list of edges*/
int freeEdges(Edge** head)
{
	if (*head == NULL)
	{
		return 1;
	}

	freeEdges(&((*head)->next));


	free(*head);
	return 1;
}

