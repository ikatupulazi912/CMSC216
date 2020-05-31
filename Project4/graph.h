typedef struct edge Edge;
typedef struct vertex Vertex;

struct edge
{
    int dest;
    Edge* next;

};

struct vertex
{
    int value;
    int numE;
    Vertex* next;
    Edge* head;
};

Edge* searchEdge(Vertex**, int);

int createVertex(Vertex**);

Vertex* addVertex(Vertex**, int);

Vertex* addEdge(Vertex**, int, int);

Vertex* searchVertex(Vertex**, int);

int check(Vertex**, int, int);

int freeVertices(Vertex**);

int freeEdges(Edge**);


