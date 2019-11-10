#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Graph.h>
int check(struct adjList *list, int v){
    if (list == NULL) return 0;
    if (list->v == v) return 1;
    return check(list->next, v);
}
Graph makeG(int size){
    Graph tmp = malloc(sizeof(struct graph));
    tmp->nV = size;
    tmp->nE = 0;
    tmp->vertices = malloc(sizeof(struct node) * (size));
    for (int i = 0; i < size; i++){
        tmp->vertices[i].nE = 0;
        tmp->vertices[i].edge = NULL;
    }
    return tmp;
}

void addEdge_s(Graph g, int a, int b, int w){
   // if (check(g->vertices[a].edge, b) == 0){
        g->vertices[a].nE++;
        g->nE++;
        struct adjList *tmp = malloc(sizeof(struct adjList));
        tmp->v = b;
        tmp->w = w;
        tmp->next = g->vertices[a].edge;
        g->vertices[a].edge = tmp;
   // }
}
void addEdge(Graph g, int a, int b, int w){
    addEdge_s(g, a, b, w);
    addEdge_s(g, b, a, w);
}
void showGraph(Graph g){
    for (int i = 0; i < g->nV; i++){
        printf("%d->", i);
        struct adjList *tmp = g->vertices[i].edge;
        while(tmp != NULL){
            printf("%d, ",tmp->v);
            tmp = tmp->next;
        }
        printf("\n");
    }
    
}
void freeNode(struct adjList *n){
    if (n == NULL) return;
    freeNode(n->next);
    free(n);
}
void freeGraph(Graph g){
    for (int i = 0; i <g->nV; i++){
        freeNode(g->vertices[i].edge);
    }
    free(g->vertices);
    free(g);
}