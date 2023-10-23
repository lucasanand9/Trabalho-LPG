void menu(int *cont);
void inserirNovoConjunto(int *cont, int m); //1
void inserirDados(int m, int n, int matriz[m][n], int *cont);//2
void deletarConjunto(int m, int n, int matriz[m][n], int conj, int *cont);//3
void uniaoConjuntos(int c1, int c2,int m, int n,int matriz[m][n],int *cont);//4
void interseccaoConjutos(int c1, int c2,int m, int n,int matriz[m][n],int *cont);//5
void mostrarUmConjunto(int m, int n, int matriz[m][n], int conj, int *cont);//6
void mostrarConjuntos(int m, int n, int matriz[m][n], int *cont);//7
void buscaValor(int m, int n, int matriz[m][n], int chave, int *cont);//8
int verificacao(int linha,int *cont);
int tamConj(int a[], int n);
void preencher_matriz(int m, int n, int matriz[m][n], int num);
int busca_seq_recursiva(int v[], int n, int chave);
int busca_seq_recursiva_aux(int v[], int n, int chave, int aux);