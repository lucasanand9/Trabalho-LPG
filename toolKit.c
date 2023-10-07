#include "toolKit.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fun��es para vetores

void mostra_vetor( int x[], int k, char nome[] ){
	int i;
	printf("%s", nome);
	for( i = 0 ; i < k ; i++ ){
		printf("%d ", x[i] );
	}
	printf("\n");
}

void mostra_vetor_2( int x[], int k, char nome[] ){
	int i;
	printf("%s\n", nome);
	for( i = 0 ; i < k ; i++ ){
		printf("%d: %d\n", i, x[i] );
	}
	printf("\n");
}

void selection_sort( int x[], int k ){
	int i;
	for( i = 0 ; i < k-1 ; i++ ){
		int i_menor = i , j;
		for( j = i+1 ; j < k ; j++ ){
			if( x[j] < x[i_menor] )
				i_menor = j;
		}
		int aux = x[i];
		x[i] = x[i_menor];
		x[i_menor] = aux;
		//Mostra vetor parcialmente ordenado.
		/*
		printf("(i=%d): ", i);
		for( j = 0 ; j < k ; j++ )
			printf("%d ", x[j] );
		printf("\n");
		*/
	}
}

void gera_valores( int x[], int k, int limite ){
	int i;
	srand( time( 0 ) ); // Define a "semente" do rand() como sendo a hora atual
	for( i = 0 ; i < k ; i++ )
		x[i] = rand() % limite + 1 ; // Gera um n�mero entre 1 e limite.
}

void gera_valores_ordem( int x[], int k, int limite ){
	int i;
	srand( time( 0 ) ); // Define a "semente" do rand() como sendo a hora atual
	x[0] = rand() % limite + 1 ; // Gera o 1o valor.
	for( i = 1 ; i < k ; i++ )
		x[i] = x[i-1] + rand() % 10 + 1 ; // Gera incremento entre 1 e 10.
}

void bubble_sort( int x[], int k ){
	int i, trocou;
	do{
		trocou = 0;
		for( i = 0 ; i < k-1 ; i++ ){
			if( x[i] > x[i+1] ){
				int aux = x[i];
				x[i] = x[i+1];
				x[i+1] = aux;
				trocou = 1;
			}
		}
		//Mostra vetor parcialmente ordenado.
		/*
		int j;
		printf("v: ");
		for( j = 0 ; j < k ; j++ )
			printf("%d ", x[j] );
		printf("\n");
		*/
	}while( trocou );
}

int busca_binaria( int x[], int n, int chave ){
	int ini = 0, fim = n-1, meio;
	int cont = 0;
	do{
		cont++; // Registra a contagem de itera��es;
		meio = ( ini + fim ) / 2;
		if( x[meio] == chave ){
			printf("[Busca executada em %d iteracoes.]\n", cont);
			return meio;
		}
		if( x[meio] < chave )
			ini = meio + 1;
		else
			fim = meio - 1;		
	}while( ini <= fim );
	printf("[Busca executada em %d iteracoes.]\n", cont);
	return -1;
}

void prencher_vetor(int v[], int n, int fill){
	for(int i = 0; i < n; i++){
		v[i] = fill;
	}
}

void inverte_vetor(int v[], int n){
	int aux;
	int imax = n-1;
	for(int i = 0; i < n/2; i++){
		aux = v[i];
		v[i] = v[imax-i];
		v[imax-i] = aux;
	}
}

int compara_vetores(int m, int v[], int h[]){
    for (int i = 0; i < m; i++){
        if (v[i] != h[i]){
            return 0;
        }
    }
    return 1;   
}

void fibonacci(int v[], int n){
    v[0] = 1;
    v[1] = 1;
    for(int i = 2; i< n; i++){
        v[i] = v[i-2] + v[i-1];
    }
}

int soma_primos(int v[], int n){
    int sum = 0;
    for(int i =0; i< n; i++){
        if (isPrimo(v[i])){
            sum += v[i];
        }
    }
    return sum;
}

void busca_todos(int v[], int n, int chave, int ind[]){
    int cont = 0;
    for(int i = 0; i< n; i++){
        if (v[i] == chave){
            ind[cont] = i;
            cont++;
        }
    }
}

int busca_seq_recursiva(int v[], int n, int chave){
    
    return busca_seq_recursiva_aux(v, n, chave, 0);
    
}

int busca_seq_recursiva_aux(int v[], int n, int chave, int aux){
    if (aux == n){
        return -1;
    }
    if (v[aux] == chave){
        return aux;
    }
    return busca_seq_recursiva_aux(v, n, chave, aux+1);
    
    
}

void pega_valores(int v[], int n){
	for(int i = 0; i < n; i++){
		scanf("%i", &v[i]);
	}
}






// Fun��es para matrizes

void gera_valores_matriz( int lin, int col, int x[lin][col] ){
	int i, j;
	for( i = 0 ; i < lin ; i++ )
		for( j = 0 ; j < col ; j++ )
			x[i][j] = rand() % 10;
}

void mostra_matriz( int lin, int col, int x[lin][col] ){
	int i, j;
	printf("Dados da Matriz %dx%d:\n", lin, col);
	for( i = 0 ; i < lin ; i++ ){
		for( j = 0 ; j < col ; j++ ){
			printf("%4d\t", x[i][j]);
		}
		printf("\n");
	}
}

void diagonal_principal( int dim, int x[dim][dim] ){
	int i, j;
	printf("Diagonal Principal: ");
	for( i = 0 ; i < dim ; i++)
		printf("%d ", x[i][i]);
	/*
	for( i = 0 ; i < dim ; i++ )
		for( j = 0 ; j < dim ; j++ )
			if( i == j )
				printf("%d ", x[i][j]);
	*/
	printf("\n\n");
}

void diagonal_secundaria( int dim, int x[dim][dim] ){
	int i, j;
	printf("Diagonal Secundaria: ");
	for( i = 0 ; i < dim ; i++)
		printf("%d ", x[i][dim-1-i]);
	/*
	for( i = 0 ; i < dim ; i++ )
		for( j = 0 ; j < dim ; j++ )
			if( i + j == dim-1 ) // j == dim-1-i
				printf("%d ", x[i][j]);
	*/
	printf("\n\n");
}

float medias_pares(int lin, int col, int x[lin][col]){
	float medias = 0, cont = 0;
	for (int i = 0; i < lin; i++){
		for (int j = 0; j < col; j++){
			if (x[i][j]%2 == 0){
				medias += x[i][j];
				cont ++;
			}
		}
	}
	if (cont == 0){
		//gambiarra para n dar erro se divisivel por 0
		return 0;
	}
	return medias/cont;
}

void gera_trasnposta(int lin, int col, int x[lin][col], int t[col][lin]){
	for (int i = 0; i < lin; i++){
		for (int j = 0; j < col; j++){
			t[j][i] = x[i][j];
		}
		
	}
	
}

void soma_matriz(int lin, int col, int x[lin][col], int y[lin][col],int soma[lin][col]){
	for (int i = 0; i < lin; i++){
		for (int j = 0; j < col; j++){
			soma[i][j] = x[i][j] + y[i][j];
		}
	}
}

void multiplica_matriz(int lin_a, int col_a, int m[lin_a][col_a],int lin_b, int col_b,  int m2[lin_b][col_b], int mult[lin_a][col_b]){
	for (size_t i = 0; i < lin_a; i++){
		for (int j = 0; j < col_b; j++){
			int soma = 0;
			for(int k = 0; k < col_a;k++){
				soma += m[i][k]*m2[k][j];
			}
			mult[i][j] = soma;
		}
	}
	
}

void preencher_matriz(int m, int n, int matriz[m][n], int num){
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            matriz[i][j] = num;
        }
    }    
}










//funcoes matematicas

int min(int a, int b){
	return a*(a<=b) + b*(b<a);
}
int max(int a, int b){
	return a*(a>=b) + b*(b>a);
}

int isPrimo(int n){
	if (n == 0 || n == 1){
		return 0;
	}
	
	for (int i = 2; i <= n/2; i++){
		if (n%i == 0){
			return 0;
		}
	}
	return 1;
	
}



















