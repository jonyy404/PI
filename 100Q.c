#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}


// 51 

int length (LInt l){
    int r;
    r = 0;
    while(l != NULL) {
        r++;
        l =l -> prox;
    }
    return r;
}

// 52 

void freeL (LInt l) {
    while (l != NULL) {
         free(l);
	 l = l->prox;
    }
}

// 53 

void imprimeL (LInt l) {
    while (l != NULL) {
	printf("%d\n", l->valor);
	l = l->prox;
    }
}

// 54 

LInt reverseL (LInt l){
    LInt next = NULL;
    LInt last = NULL;
    while(l != NULL){
        	next = l->prox;
        	l->prox = last;
        	last = l;
        	l = next;
    }
    	l = last;
    	return l;
}

// 55 

void insertOrd (LInt *l, int x){
    LInt aux = *l;
    LInt ant = NULL;
    LInt novo = (LInt) malloc(sizeof(struct lligada));
    while (aux != NULL && aux->valor < x) {
        ant = aux;
        aux = aux->prox;
    }
    novo -> valor = x;
    novo -> prox = aux;
    if (ant == NULL){
        (*l) = novo;
        novo->prox = aux;
    }
    else {
        ant->prox = novo;
        novo->prox = aux;
    }
}

// 56 

int removeOneOrd (LInt *l, int x){
    int r=1;
    LInt aux = *l;
    LInt ant = NULL;
    while (aux != NULL && aux->valor != x) {
        ant = aux;
        aux = aux->prox;
    }
    if (ant == NULL) {
        if (aux != NULL) {
            free(aux);
            (*l) = NULL;
            r=0;
        }
    }
    else {
        if (aux != NULL) {
            free(aux);
            ant->prox = aux->prox;
            r=0;
        }
    }
    return r;
}

// 57

void merge (LInt *r, LInt l1, LInt l2){
    LInt aux = *r;
    if (l1 == NULL )  aux = l2;
    else if (l2 == NULL )  aux = l1;
    else if ( l1->valor > l2->valor) {
        aux = l2;
        merge ( &(aux->prox) , l1 ,l2->prox);
    }
    else if ( l1->valor <= l2->valor) {
        aux= l1 ;
        merge ( &(aux->prox), l1->prox ,l2);
    }
    *r = aux;
}

// 58

// 59 

LInt parteAmeio (LInt *l){
    LInt aux = *l;
    LInt ant = NULL;
    LInt r; 
    int m = (length(*l)/2);
    if (aux == NULL) return NULL;
    if (m<=0) return NULL; 
    while (m>0) {
        if (ant == NULL) {
            r = aux;
        }
        else {
            ant->prox = aux;
        }
        ant = aux;
        aux = aux->prox;
        m--;        
    }
    *l = aux;
    ant->prox = NULL;    
    
    return r;
}

// 60 

int removeAll (LInt *l, int x){
    LInt ant;
    int c = 0;
    while (*l != NULL){
        ant = *l;
        if ((*l)->valor == x){
            *l = (*l) -> prox;
            ant -> prox = *l;
            c++;
        } else l = &((*l)->prox);
    }
    return c;
}

// 61  

int removeDups (LInt *l){
    LInt ant = NULL;
    int x;
    int c=0;
    while (*l != NULL){
        x = (*l)->valor;
        c += removeAll(&((*l)->prox),x);
        l = &((*l)->prox);
    }
    return c;
}

// 62

int removeMaiorL (LInt *l){
    LInt aux = (*l);
    int maior = 0;
    while (aux != NULL) {
        if (aux->valor > maior) maior = aux->valor;
        aux = aux->prox;
    }
    removeOneOrd(l,maior);
    return maior;
}

// 63

void init (LInt *l){
    LInt aux = (*l);
    LInt ant = NULL;
    while (aux->prox != NULL) {
        ant = aux;
        aux = aux->prox;
    }
    if (ant != NULL) { ant->prox = NULL; }
    else (*l) = NULL;
}

// 64 

void appendL (LInt *l, int x){
    LInt aux = (*l);
    LInt novo = newLInt(x,NULL);
    if (aux == NULL) (*l) = novo;
    else {
        while (aux->prox != NULL) {
            aux = aux->prox;    
        }
        aux->prox = novo;
    }
}

// 65

void concatL (LInt *a, LInt b){
    LInt auxdea = *a;
    if (auxdea == NULL) (*a) = b;
    else {
        while (auxdea->prox != NULL) {
            auxdea = auxdea->prox;
        }
        auxdea->prox = b;
    }
}

// 66

LInt cloneL (LInt l) {
    LInt aux =  l;
    LInt novo;
    while (aux != NULL) {
        novo = newLInt(aux->valor,NULL);
        novo = novo->prox;
        aux = aux->prox;
    }
    return novo;
}

// 67 

LInt cloneRev (LInt l){
    LInt prox = NULL, atual;
    for (prox = NULL ; l !=NULL ; l = l->prox, prox = atual) atual = newLInt(l->valor, prox);
    return atual;
}

// 68

int maximo (LInt l){
    int max = l->valor;
    while (l != NULL) {
        if (l->valor > max) max = l->valor;
        else l = l->prox;
    }
    return max;
}

// 69

int take (int n, LInt *l){
    int c=0;
    LInt aux = *l;
    LInt ant;
    for (c = 0; aux != NULL && n>0; c++) {
        n--;
        ant = aux;
        aux = aux->prox;
    }
    if (aux != NULL) {
        ant->prox = NULL;
        free(aux);
        aux = aux->prox;
    }
    return c;
}

// 70

int drop (int n, LInt *l){
    LInt aux = *l;
    int c;
    for (c=0; aux != NULL && n>0; c++) {
        n--;
        free(aux);
        aux = aux->prox;
    }
    (*l) = aux;
    return c;
}

// 71 -

LInt NForward (LInt l, int N){
    while (N > 0) {
        l = l->prox;
        N--;
    }
    return l;
}

// 72

int listToArray (LInt l, int v[], int N){
    int i;
    for (i=0; i<N && l; i++) {
        v[i] = l->valor;
        l = l->prox;
    }
    return i;
}

// 73 

LInt arrayToList (int v[], int N){
    int i;
    LInt l=NULL,aux;
    for (i=N-1;i>=0;i--) {
        aux = malloc (sizeof (struct lligada));
        aux->valor = v[i];
        aux->prox = l;
        l = aux;
    }
    return l;
}

// 74

LInt somasAcL (LInt l) {
    if (l == NULL) return NULL;
    LInt atual = l;
	LInt novo = newLInt (atual->valor, NULL);
	LInt auxnovo = novo;
	int soma = atual->valor;
	while (atual->prox != NULL) {
		atual = atual->prox;
		soma += atual->valor;
		auxnovo->prox = newLInt (soma, NULL);
		auxnovo = auxnovo->prox;
	}
	return novo;
}

// 75 

void remreps (LInt l){
    LInt ant = NULL;
    LInt aux = l;
    int x; 
    while (aux != NULL) {
        if (ant == NULL) {
            x = aux->valor;
            ant = aux;
            aux = aux->prox;
        }
        else {
            while (aux != NULL && aux->valor == x) {
                free(aux);
                aux = aux->prox;
            }
            ant->prox = aux;
            if (aux != NULL) {
                ant = aux;
                x = aux->valor;
                aux = aux->prox;
            }
        }
    }
}

// 76

LInt rotateL (LInt l){
    LInt aux = l;
    LInt aux2 = NULL;
    if (l == NULL) return l;
    if (l->prox == NULL) return l;
    aux2 = aux->prox;
    while (l->prox != NULL){
        l = l->prox;       
    }
    l->prox = aux;
    aux->prox = NULL;
    return aux2;
}

// 77

//

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;


// 78

int max (int x, int y) {
    if (x>y) return x;
    else return y;
}

int altura (ABin a){
    int c;
    if (a == NULL) return 0;
    else {
        c = 1 + max(altura(a->esq),altura(a->dir));
    }
	return c;
}

// 79

ABin cloneAB (ABin a) {
    ABin b;
    b = (ABin) malloc(sizeof(struct nodo));
    if (a != NULL) { 
    b->valor = a->valor;
    b->esq = cloneAB(a->esq);
    b->dir = cloneAB(a->dir);
    }
    else b = NULL;
    return b;
}

// 80

void mirror (ABin *a) {
    ABin aux;
    if ((*a) != NULL) {
    aux = (*a)->esq;
    (*a)->esq = (*a)->dir;
    (*a)->dir = aux;
    mirror(&((*a)->esq));
    mirror(&((*a)->dir));
    }
}

// insere fim (usado no 81, 82, 83)

void inserefim(LInt *a,int x){
    LInt aux=*a;
    while (aux && aux->prox){
        aux=aux->prox;
    }
    if(aux){
        aux->prox=newLInt(x,NULL);
    }
    else{
        *a=newLInt(x,NULL);
    }
}

// 81

void inorder (ABin a, LInt * l) {
    if (a != NULL) {
        inorder(a->esq,l);
        inserefim(l,a->valor);
        inorder(a->dir,l);
    }
}

// 82 

void preorder (ABin a, LInt * l) {
    if (a != NULL) {
        inserefim(l,a->valor);
        preorder(a->esq,l);
        preorder(a->dir,l);
    }
}

// 83 

void posorder (ABin a, LInt * l) {
    if (a != NULL) {
        posorder(a->esq,l);
        posorder(a->dir,l);
        inserefim(l,a->valor);
    }
}

// 84

int depth (Abin a, int x) {
	int c = 1;
	if (a == NULL) c =  -1;
	else if (a->valor == x) {
		c = 1;
	}
	else {
		int esq = depth (a->esq, x);
		int dir = depth (a->dir, x);
	    if (esq == -1 && dir == -1) c = -1;
		else if (esq == -1 && dir != -1) c += dir;
		else if (esq != -1 && dir == -1) c += esq;
		else {
			if (esq < dir) c += esq;
			else c += dir;
		}
	}
    return c;
}

// 85

int freeAB (ABin a) {
    int c = 0;
    if (a == NULL) return 0;
    free(a);
    c = 1 + freeAB(a->esq) + freeAB(a->dir);
    return c;
}

// 86 

int pruneAB (ABin *a, int l) {
    int c=0;
    if ((*a) != NULL) {
         if (l > 0) {
            c = pruneAB(&((*a)->dir),l-1);
            c += pruneAB(&((*a)->esq),l-1);
        }
         else {
            free(*a);
            c = 1 + pruneAB(&((*a)->dir),l-1);
            c += pruneAB(&((*a)->esq),l-1);
            (*a) = NULL;
        }
    }
    return r;
}

// 87 

int iguaisAB (ABin a, ABin b) {
    if (a != NULL && b == NULL || a == NULL && b != NULL) return 0;
    else if (a == NULL && b == NULL) return 1;
    else if (a->valor != b->valor) return 0; 
    return (iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir));
}

// 88 

void adiciona (ABin a, int n, LInt *l) {

	if (a == NULL) return;

	if (n == 1) {
		*l = newLInt(a->valor, *l);
	}
	else {
		adiciona(a->dir, n-1, l);
		adiciona(a->esq, n-1, l);
	}
}

LInt nivelL (ABin a, int n) {

	LInt novo = NULL;
	adiciona(a, n, &novo);

	return novo;
}

// 89

int nivelV (ABin a, int n, int v[]) {
    int c=0;
    if (a != NULL) {
        if (n == 1) {
            v[0] = a->valor;
            c = 1;
        }
        else {
            c = nivelV(a->esq,n-1,v);
            c += nivelV(a->dir,n-1,v+c);
        }
    }
    return c;
}

// 90

int dumpAbin (ABin a, int v[], int N) {
    int c = 0;
    if (a != NULL) {
        c = dumpAbin (a->esq,v,N);
        if ((N-c) > 0) {
            c += 1;
            v[c] = a->valor;
            c += dumpAbin(a->dir,v+c,N-c);
        }
    }
    return c;
}

// 91

int auxsoma (ABin a){
    if (a == NULL) return 0;
    return a->valor + auxsoma(a->esq) + auxsoma(a->dir);
}

ABin somasAcA (ABin a) {
    ABin nova = (ABin) malloc(sizeof(struct nodo));
    int c = 0;
    if (a == NULL) return NULL;
    else {
        c += auxsoma(a);
        nova->valor = c;
        nova->esq = somasAcA(a->esq);
        nova->dir = somasAcA(a->dir);
    }
    return nova;
}

// 92

int contaFolhas (ABin a) {
    int c=0;
    if (a != NULL) {
        if (a->esq == NULL && a->dir == NULL) {
            c = 1;
        }
        else c += contaFolhas(a->esq) + contaFolhas(a->dir);
    }
    return c;
}

// 93 

ABin cloneMirror (ABin a) {
    ABin nova = NULL;
    if (a != NULL) {
        nova = malloc(sizeof(ABin));
        nova->valor = a->valor;
        nova->esq = cloneMirror(a->dir);
        nova->dir = cloneMirror(a->esq);
    }
    return nova;
}

// 94

int addOrd (ABin *a, int x) {
    ABin aux = *a;
    ABin ant = NULL;
    while (aux != NULL) {
        if ( x == aux -> valor)
            return 1;
            
        ant = aux;
        
        if ( x > aux -> valor) 
            aux = aux -> dir;
        else aux = aux -> esq;
    }
    
    aux = malloc (sizeof (ABin));
    aux -> valor = x;
    aux -> esq = aux -> dir =  NULL;

    if (ant == NULL) {
        (*a) = aux;
    }
    else {
        if (x > ant -> valor)
            ant -> dir = aux;
        else ant -> esq = aux;
    }
    return 0;
}

// 95

int lookupAB (ABin a, int x) {
    int r=0;
    if (a == NULL) return 0;
    while (a != NULL) {
        if (a->valor == x) return 1;
        else {
            if (a->valor > x) a = a->esq;
            else a = a->dir;
        }
    }
    return r;
}

// 96

int depthOrd (ABin a, int x) {
    int r=1;
    while (a != NULL) {
        if (a->valor == x) return r;
        else {
            if (a->valor > x) a = a->esq;
            else a = a->dir;
            r++;
        }
    }
    return -1;
}

// 97 

int maiorAB (ABin a) {
    int maior = 0;
    if (a == NULL) return 0;
    while (a->dir != NULL) a = a->dir;
    maior = a->valor;
    return maior;
}

// 98

void removeMaiorA (ABin *a) {
    ABin aux = *a;
    ABin ant = NULL;
    while (aux->dir != NULL) {
        ant = aux;
        aux = aux->dir;
    }
    if (ant == NULL) (*a) = (*a)->esq;
    else ant->dir = aux->esq;
}

// 99

int quantosMaiores (ABin a, int x) {
    int c=0;
    if (a == NULL) return;
    if (a->valor > x) c = (1 + quantosMaiores(a->dir,x) + quantosMaiores(a->esq,x));
    else c = (quantosMaiores(a->dir,x));
    return c;
}

// 100

void listToBTree (LInt l, ABin *a) {
	if (l == NULL) {
		*a = NULL;
		return;
	}
	LInt dir = parteAMeio (&l);
	*a = newABin (dir->valor, NULL, NULL);
	listToBTree (l, &(*a)->esq);
	listToBTree (dir->prox, &(*a)->dir);

	return;
}

// 101

int procuraMenor (ABin a, int x) {
	int r;
	if (a == NULL) r = 0;
	else if (a->valor < x) r = 1;
	else if (procuraMenor (a->esq, x) == 1 || procuraMenor (a->dir, x) == 1) r = 1;
	else r = 0;
    return r;
}

int procuraMaior (ABin a, int x) {
	int r;
	if (a == NULL) r = 0;
	else if (a->valor > x) r = 1;
	else if (procuraMaior (a->esq, x) == 1 || procuraMaior (a->dir, x) == 1) r = 1;
	else r = 0;
	return r;
}

int deProcura (ABin a) {
	int r;
	if (a == NULL) r = 1;
	else if (procuraMaior (a->esq, a->valor) == 1 || procuraMenor (a->dir, a->valor) == 1) r = 0;
	else if (deProcura (a->esq) == 0 || deProcura (a->dir) == 0) r = 0;
	else r = 1;
	return r;
}
