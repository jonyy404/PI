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
