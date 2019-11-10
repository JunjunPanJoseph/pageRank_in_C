typedef struct adjList{
    int v;
    int w;
    struct adjList *next;
} *Node;

struct node{
    //double prob;
    int nE;
    struct adjList* edge;
};

typedef struct graph{
    int nV;
    int nE;
    struct node *vertices;
} *Graph;
int check(struct adjList *list, int v);
Graph makeG(int size);
void addEdge_s(Graph g, int a, int b, int w = 0);
void addEdge(Graph g, int a, int b, int w = 0);
void showGraph(Graph g);
void freeNode(struct adjList *n);
void freeGraph(Graph g);