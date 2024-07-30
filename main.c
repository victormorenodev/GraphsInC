#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOPESO;

#define BRANCO 0
#define CINZA 1
#define PRETO 2

typedef struct adjacencia {
	int vertice;
	TIPOPESO peso;
	struct adjacencia *prox;
}ADJACENCIA;

typedef struct vertice {
	ADJACENCIA *cab;
}VERTICE;

typedef struct grafo {
	int vertices;
	int arestas;
	VERTICE *adj;
}GRAFO;

void visitaP(GRAFO *g, int u, int *cor) {
	printf("VÉRTICE VISITADO: %c"); 
	cor[u] = CINZA;
	ADJACENCIA *v = g->adj[u].cab;
	while(v) {
		if (cor[v->vertice] == BRANCO) {
			visitaP(g, v->vertice,cor);
			v = v->prox;
		}
	}
	cor[u] = PRETO;
}

void profundidade (GRAFO *g) {
	int cor[g->vertices];

	int u;
	for(u=0;u<g->vertices;u++){
		cor[u] = BRANCO;
	}
	for(u=0;u<g->vertices;u++){
		if(cor[u] == BRANCO) {
			visitaP(g, u, cor);
		}
	}
}

int main() 
{
	GRAFO g;
	VERTICE a, b, c, d, e, f;
	ADJACENCIA ab, ae, bc, be, ed, cd, df;
	ab.vertice = 2; ae.vertice = 5; bc.vertice = 3; be.vertice = 5; ed.vertice = 4; cd.vertice = 4; df.vertice = 6;
	ab.prox = &b; ae.prox = &e; bc.prox = &c; be.prox = &e; ed.prox = &e; cd.prox = &d; df.prox = &f;
       	a.cab = &b; b.cab = &c; c.cab = &d; d.cab = &f; f.cab = NULL;
	g.vertices = 6;
	g.arestas = 7;
	g.adj = &f;
	profundidade(&g);
	return(0);
}
