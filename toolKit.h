// Fun��es para vetores
void gera_valores( int x[], int k, int limite );
void gera_valores_ordem( int x[], int k, int limite );
void mostra_vetor( int x[], int k, char nome[] );
void mostra_vetor_2( int x[], int k, char nome[] );
void selection_sort( int x[], int k );
void bubble_sort( int x[], int k );
int busca_binaria( int x[], int n, int chave );
void prencher_vetor(int v[], int n, int fill);
void inverte_vetor(int v[], int n);
int compara_vetores(int m, int v[], int h[]);
void fibonacci(int v[], int n);//salva os valores da sequencia ate preencher o vetor
int soma_primos(int v[], int n);
void busca_todos(int v[], int n, int chave, int ind[]);
int busca_seq_recursiva(int v[], int n, int chave);
int busca_seq_recursiva_aux(int v[], int n, int chave, int aux);
void pega_valores(int v[], int n);


// Fun��es para matrizes
void mostra_matriz( int lin, int col, int x[lin][col] );
void gera_valores_matriz( int lin, int col, int x[lin][col] );
void diagonal_principal( int dim, int x[dim][dim] );
void diagonal_secundaria( int dim, int x[dim][dim] );
float medias_pares(int lin, int col, int x[lin][col]);
void gera_trasnposta(int lin, int col, int x[lin][col], int t[col][lin]);
void soma_matriz(int lin, int col, int x[lin][col], int y[lin][col],int soma[lin][col]);
void multiplica_matriz(int lin_a, int col_a, int m[lin_a][col_a],int lin_b, int col_b,  int m2[lin_b][col_b], int mult[lin_a][col_b]);
void preencher_matriz(int m, int n, int matriz[m][n], int num);
//fazer copia de matriz
//inversa de matriz
//pegar valor matriz
//multiplicar por const

//Funçoes matematicas
int min(int a, int b);
int max(int a, int b);
int isPrimo(int n);

