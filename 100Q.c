51 -

int length (LInt l){
    int r;
    r = 0;
    while(l != NULL) {
        r++;
        l =l -> prox;
    }
    return r;
}

52 - 

void freeL (LInt l) {
    while (l != NULL) {
         free(l);
	 l = l->prox;
    }
}

53 - 

void imprimeL (LInt l) {
    while (l != NULL) {
	printf("%d\n", l->valor);
	l = l->prox;
    }
}

54 - 

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

55 -

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

56 -

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

57 - 

59 -

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

60 -

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

61 - 

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
