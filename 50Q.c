
// 4 - 

int bitsUm (unsigned int x){
    int r=0;
    while (x != 0) {
        if (x%2 == 0) x = x/2;
        else {
            r++;
            x = x/2;
        }
    }
    return r;
}

// 5 -

int trailingZ (unsigned int n) {
    int r=0;
    if (n%2 == 1) return 0;
    while (n%2 == 0) {
        n = n/2;
        r+=1;
    }
    return r;
}

// 6 - 

int qDig (int n) {
    int r = 0;
    while (n != 0) {
        r += 1;
        n = n/10;
    }
    return r;
}

// 7 - 

char *mystrcat(char s1[], char s2[]) {
    int i,j;
    for (i=0; s1[i] != '\0'; i++);
        for (j=0; s2[j] != '\0'; j++) {
           s1[i] = s2[j];
           i++;
        }
    s1[i] = '\0';
    return s1;
}

// 8 -

char *mystrcpy(char s1[], const char s2[]) {
    int i;
    for (i=0; s2[i] != '\0'; i++) s1[i] = s2[i];
    s1[i] = '\0';
    return s1;
}

// 9 - 

int mystrcmp(char s1[], char s2[]) {
    int i,j;
    for (i=0,j=0; s1[i] != '\0' && s2[j] != '\0'; i++,j++) {
        if (s1[i] < s2[j]) return -1;
        if (s1[i] > s2[j]) return 1;
    }
    if (s1[i] == s2[j]) return 0;
    else if (s1[i] < s2[j]) return -1;
    else return 1;
}

// 10 - 

char *mystrstr (char s1[], char s2[]) {
	int i,j = 0;
	if (*s2 == '\0') return s1;
	for (i = 0;s1[i] != '\0';i++){
		if (s1[i] != s2[j]);
		else j++;
		if (s2[j] == '\0') return s1+i-j+1; //Pk este valor  ?? i dont fucking know mas funciona.
	    }
	return NULL;
}

// 11 - 

void strrev (char s[]) {
    char v[strlen(s)-1];
    int i,j=0;
    for(i=strlen(s)-1;i>= 0;i--) {
        v[j] = s[i];
        j++;
    }
    v[j] = '\0';
    strcpy(s,v);
}

// 12 - 

int retiravogais (char c){
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' ||c == 'u') return 1;
    else return 0;
}


void strnoV (char t[]){
    int i;
    int j=0;
    char s[strlen(t)-1];
    for(i=0;t[i] != '\0';i++) {
        if (retiravogais(t[i]) == 0) { s[j++] = t[i]; }
    }
    s[j] == '\0';
    strcpy(t,s);
}

// 13 -

void truncW (char t[], int n){
    int i, j = 0, repetir = n;
    for (i = 0; t[i] != '\0'; i++) {
        if (t[i] == ' ') {
        	repetir = n;
        	t[j] = t[i];
        	j++;
        }
        else {
        	if (repetir != 0) {
        	t[j] = t[i];
        	repetir--;
        	j++;
        	}
    	}
	}
    t[j] = '\0';
}

// 14 - 

char charMaisfreq (char s[]) {

    int i, guarda = 0,contador,indice;
    char aquelequeaparecemais,teste;
    for ( i = 0; s[i] != '\0'; i++){
        contador = 0;
        teste = s[i];
        indice = i;
        while (s[indice] != '\0'){
            if (s[indice] == teste){
                contador++;
                indice++;
            }
            else indice++;
        }
        if (contador > guarda){
            guarda = contador;
            aquelequeaparecemais = teste;
        }
    }
    return aquelequeaparecemais;
}

// 15 - 

int iguaisConsecutivos (char s[]) {
    int i,c=1,rep=0;
    if (s[1] == '\0'){
        rep = 1;
        return rep;
    }
    for(i=0;s[i] != '\0';i++){
        if (s[i] == s[i+1]) { 
            c++;
            if (c>rep) rep = c;   
        }
        else c=1;
    }
    
    return rep;
}

// 16 -

int difConsecutivos(char s[]) 
{
 int i, j, l = strlen(s), conta, maior;
 for (i=0, maior = 0 ; i<l ; i++)
 {
    int ocorr[256] = {0};
    for (j=i, conta = 0 ; s[j] != 0 ; j++)
    {
        if (!ocorr[s[j]]) {conta++; ocorr[s[j]] = 1;}  // Se ainda nao ocorreu aumenta o contador e muda o valor no array a dizer que ocorreu
        else break;  // se ja ocorreu para o ciclo
    }
    maior = (conta>maior) ?conta :maior;  // o maior fica com o maior valor entre o contador e o maior
 }
 return maior;   
}

// 17 - 

int maiorPrefixo (char s1 [], char s2 []) {
    int i;
    for(i=0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
    return i;
}

// 18 -

int comprimento (char s[]) {
    int i;
    for (i=0; s[i] != '\0'; i++);
    return i;
}

int maiorSufixo (char s1 [], char s2 []) {
    int i,j,c=0;
    i = comprimento(s1)-1;
    j = comprimento(s2)-1;
    for (; i>0 || j>0; i--, j--) {
        if (s1[i] == s2[j]) c++;
        else return c;
    }
    return c;
}

// 19 - 

int comprimento (char s[]) {
    int i;
    for (i=0; s[i] != '\0'; i++);
    return i;
}

int sufPref (char s1[], char s2[]) {
    int inicio, i, r=0, atual;

    for (inicio=0 ; s1[inicio]!=0 ; inicio++) {
        atual = 0;
        for (i=0 ; (s1+inicio)[i]!=0 ; i++) {
            if ((s1+inicio)[i] != s2[i]) atual = 0;
            else atual++;
        }
        if (atual>r) r=atual;
    }
    return r;
}

// 20 - 

int contaPal (char s[]) {
    int i,c=0;
    for (i=0; s[i] != '\0';i++) {
        if (s[i] != ' ' && s[i] != '\n' && (s[i-1] == ' ' || s[i-1] == '\0')) c++;
    }
    return c;
}

// 21 - 

int contaVogais (char s[]) {
    int i, c=0;
    for (i=0; s[i] != '\0';i++) {
    if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') c++;
    }
    return c;
}

// 22 - 

int estaEm (char a, char s[]) {
    int i;
    for (i=0 ; s[i]!=0 ; i++) if (s[i] == a) return 1;
    return 0;
}

int contida (char a[], char b[]) {
    int i;
    for (i=0 ; a[i]!=0 ; i++) if (estaEm(a[i], b) == 0) return 0;
    return 1;
}

// 23 - 

int palindroma (char s[]) {
    int i,j,r=1,m;
    j = strlen(s)-1;
    m = strlen(s)/2;
    if (strlen(s)%2==0) {
        for (i=0; i<m; i++,j--){
            if (s[i] != s[j]) r=0;
        }
    } else {
        for (i=0; i<m && j>m; i++, j--) {
            if (s[i] != s[j]) r=0;
        }
    }
    return r;
}

// 24 -

int remRep (char s[]) {
    int i,j=0;
    for (i=0; s[i] != '\0';i++) {
        if (s[i] != s[i+1]) {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
    return j;
}

// 25 - 

int limpaEspacos (char s[]) {
    int i=0,j=0,c=0,indice;
    indice = i;
    char t[strlen(s)-1];
    for(; s[i] != '\0';i++) {
        if (s[i] != ' ') {
            t[j] = s[i];
            j++;
            indice++;
            c++;
        }
        else if (s[i] == ' ' && s[i+1] == s[i]){
            if (s[i] == ' ' && s[i+1] != ' '){
                t[j] = s[indice];
                j++;
                indice = i;
                c++;
            }
        }
    }
    return c;
}

// 26 -

void insere (int v[], int N, int x) {
	int j,i;
	for (i = 0;i<N && x>v[i];i++); 
	for (j = N ; j != i ;j--) 
		v[j] = v[j-1]; 
	v[i] = x;		  
}

// 27 -

   void merge (int r [], int a[], int b[], int na, int nb){
       int ia,jb,rs; 							// rs para percorrer o r
       for (ia=0,jb=0,rs=0; rs < na+nb; rs++) {
           if (ia >= na) r[rs] = b[jb++];
           else if (jb >= nb) r[rs] = a[ia++];
           else if (a[ia] <= b[jb]) r[rs] = a[ia++];
           else if (a[ia] > b[jb]) r[rs] = b[jb++];
       }
   }

// 28 - 

int crescente (int a[], int i, int j){
       int r=1;
       for (;i<j;i++) {
           if (a[i+1] < a[i]) r=0;
       }
       return r;
   }

// 29 - 

int retiraNeg (int v[], int N){
    int i,j=0;
    int s[N];
    for (i=0;i<N;i++){
        if (v[i] >= 0) s[j++] = v[i];
    }
    for (i=0;i<j;i++){
        v[i] = s[i];
    }
    return j;
}

// 30 -

int menosFreq (int v[], int N){
       int i,c=1,g=10000,menor;
       for(i=0;i<N;i++) {
            while (v[i] == v[i+1]) {c++;i++;}
            if (c<g) {
                g = c;
                menor = v[i];
                c=1;
            }
        c=1;
       }
       return menor;
   }

// 31 -

// int maisFreq (int v[], int N){
   int i,c=1,g=0,maior;
       for(i=0;i<N;i++) {
            while (v[i] == v[i+1]) {c++;i++;}
            if (c>g) {
                g = c;
                maior = v[i];
                c=1;
            }
        c=1;
       }
       return maior;
   
   }

// 32 - 

// 37 -

int minInd (int v[], int n) {
   int i,c=100000,indice;
   for(i=0;i<n;i++){
       if (v[i] < c) { c = v[i]; indice = i; }
   }
   return indice;
}

// 38 - 

void somasAc (int v[], int Ac [], int N){
   int i,c=0;
   for (i=0;i<N;i++){
       c += v[i];
       Ac[i] = c;
   }
}

// 39 - 



// 40 - 

void transposta (int N, float m [N][N]) {
    int i,j,aux;
    for (i=0;i<N;i++){
        for (j=0;j<i;j++) {
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
}

46 - 

   int cardinalMSet (int N, int v[N]){
   	  int i,c=0;
   	  for(i=0;i<N;i++) {
   	      c += v[i];
   	  }
   	  return c;
   }




