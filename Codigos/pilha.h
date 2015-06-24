/**************************************
* Trabalho 2 de Estrutura de Dados I
* Curso de Sistemas da informacão
* Aluno: Luiz Felipe Teixeira Assumpção - matricula: 0050008552
* Analise de expressão aritmetica
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define toDigit(c) (c-'0')

struct lista {
    int info;
    struct lista * prox;
};

typedef struct lista Lista;

struct pilha{
    Lista* prim;
};

typedef struct pilha Pilha;

Pilha* pilha_cria(void)
{
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->prim=NULL;
    return p;
}

void pilha_push(Pilha* p, int v)
{   
    Lista* n = (Lista*)malloc(sizeof(Lista));
    n->info=v;
    n->prox=p->prim;
    p->prim=n;
}

int pilha_vazia(Pilha* p){
    if(p->prim!=NULL)
        return 0;
    else
        return 1;
}

int pilha_pop(Pilha* p){
    Lista* t;
    int v;
    if(pilha_vazia(p)){
        printf("Pilha vazia. \n");
        exit(1);
    }
    t=p->prim;
    v=t->info;
    p->prim=t->prox;
    free(t);
    return v;
}
void pilha_libera(Pilha *p){
    Lista* q=p->prim;
    
    while(q!=NULL)
	{
        Lista* t=q->prox;
        free(q);
        q=t;
    }
    free(p);
}

