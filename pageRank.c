#include <stdio.h>
#include <stdlib.h>
#include <Graph.h>

double *tmpRankBuffer = NULL;
int tmpRankBufferSize = 0;

void initTmpRankBuffer(int size){
    tmpRankBuffer = malloc(sizeof(double) * size);
    tmpRankBufferSize = size;
}
void calcPageRank(double *pageRank,  double **Matrix, int nV){
    if (tmpRankBufferSize == nV) {
        initTmpRankBuffer(nV);
    }
    for (int i = 0; i < nV; i++){
        tmpRankBuffer[i] = 0;
        for (int j = 0; j < nV; j++){
            tmpRankBuffer[i] += pageRank[j] * Matrix[i][j];
        }
    }
    for (int i = 0; i < nV; i++){
        pageRank[i] = tmpRankBuffer[i];
    }
}
void freeMatrix(double **Matrix , int size){
    for(int i = 0 ; i < size; i++){
        free (tmpMatrix[i] );
    }
    free(Matrix);
    Matrix = NULL;
}

double **initStateTransferMatrix(Graph g){
    double **tmpMatrix = malloc(g->nV * sizeof(double *));
    for(int i = 0 ; i < g->nV; i++){
        tmpMatrix[i] = malloc(g->nV * sizeof(double));
        for (int j = 0; j < g->nV; j++){}
        tmpMatrix[i][j] = 0;
    }
    return tmpMatrix;
}
double **makeStateTransferMatrix(Graph g, double a){
    int n = g->nV;
    double **tmpMatrix = initStateTransferMatrix(g);
    if (tmpMatrix == NULL) return NULL;
    for (int i = 0; i < g->nV; i++){
        Node tmpNode = g->vertices[i]->edge;
        while(tmpNode != NULL){
            tmpMatrix[tmpNode->v][i] += 1;
            tmpNode = tmpNode ->next;
        }
    }
    for (int j = 0; i < n; j++){
        double total = 0;
        for(int i = 0; j <n; i++){
            total += tmpMatrix[i][j];
        }
        for(int i = 0; j <n; i++){
            tmpMatrix[i][j] /= total;
        }
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            tmpMatrix[i][j] = (1-a) * tmpMatrix[i][j] + a;
        }
    }
    return tmpMatrix;   
}
int updatePageRank(double *pageRank,  double **Matrix, int nV, int iterations){
    if (pageRank == NULL || Matrix == NULL) return 0;
    for(int i = 0; i < iterations; i++){
        calcPageRank(pageRank,  Matrix, nV);
    }
    return i;
}

int main(int argc, int *argv[]){
    Graph g = NULL;
    int iterations
    double a;
    double *pageRank = malloc(sizeof(double) * g->nV);
    for (int i = 0; i < g->nV; i++){
        pageRank[i] = 1;
    }
    double **transferMatrix = makeStateTransferMatrix(g, a);
    updatePageRank(pageRank, transferMatrix, iterations);
    
    if (transferMatrix != NULL) freeMatrix(transferMatrix, g->nV);
    if (tmpRankBuffer != NULL) free(tmpRankBuffer);
    return 0;
}