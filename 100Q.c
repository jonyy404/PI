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
