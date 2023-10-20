#include <stdio.h>
#include <string.h>
#include "toolKit.h"

//#define M 10
//#define N 8

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

int main(){
    int Imenu;
    int c1,c2;
    int conj;
    //variavel cont eh a mais importante
    int cont = 0;
    int M,N;
    
    printf("Bem Vindo! Digite o tamanho da matriz que deseja criar (linhas x colunas):\n");
    scanf("%d %d",&M,&N);
    int m[M][N];
    preencher_matriz(M, N, m, 0);
    
    do{
        menu(&cont);
        scanf("%i", &Imenu);
        switch (Imenu){
            case 1:
                //criar novo conjunto
                inserirNovoConjunto(&cont, M);
                printf("\nHá %d conjunto(s) registrado(s).\n", cont);
            break;
            case 2:
                //inserir conjunto
                printf("Em qual conjunto voce quer inserir valores?\n");
                scanf("%i", &conj);
                inserirDados(conj, N, m, &cont);
            break;
            case 3:
                //remover conjunto
                printf("Qual conjunto voce quer remover?\n");
                scanf("%i", &conj);
                deletarConjunto(M,N,m,conj,&cont);
            break;
            case 4:
                //unir
                printf("Digite quais conjuntos voce quer que sejam unidos:\n");
                scanf("%i%i", &c1, &c2);
                uniaoConjuntos(c1, c2, M,N,m, &cont);
            break;
            case 5:
                //intersecçao
                printf("Digite quais conjuntos voce quer que sejam interseccionados:\n");
                scanf("%i%i", &c1, &c2);
                interseccaoConjutos(c1,c2,M,N,m,&cont);
            break;
            case 6:
                //mostrar 1 conjunto
                printf("Digite qual conjunto voce quer visualizar:\n");
                scanf("%i", &conj);
                mostrarUmConjunto(M, N, m, conj, &cont);
            break;
            case 7:
                //mostrar varios conjuntos
                mostrarConjuntos(cont, N, m, &cont);
            break;
            case 8:
                //busca valor
                printf("Digite qual valor voce quer buscar dentro da matriz:\n");
                int chave;
                scanf("%i", &chave);
                buscaValor(M, N, m, chave, &cont);
            break;
        }
    }while (Imenu != 0);

    // uniaoConjuntos();
    // menu();
    // scanf("%i", &Imenu);
    //fazer o switch no final!
}

void menu(int *cont){
    printf("\n================================================\n");
    printf("Qual sua escolha para hoje?\n");
    printf("Você tem %i conjuntos criados\n", *cont);
    printf("(1) Criar um novo conjunto\n");
    printf("(2) Inserir dados em um conjunto\n");
    printf("(3) Remover um conjunto\n");
    printf("(4) Unir dois conjuntos\n");
    printf("(5) Fazer a intersecçao de dois conjuntos\n");
    printf("(6) Mostrar um conjunto\n");
    printf("(7) Mostrar todos os conjuntos\n");
    printf("(8) Buscar por um valor\n");
    printf("(0) Sair\n");
    printf("================================================\n");
}

void inserirNovoConjunto(int *cont,int m){
    if(*cont == m){
        printf("\nNao eh possivel adicionar mais conjuntos :(\nCaso queira criar um novo conjunto, exclua algum que voce nao esta mais ultilizando.\n");
        return;
    }
    *cont = *cont +1;
}

void inserirDados(int m, int n, int matriz[m][n], int *cont){
    if (cont == 0){
        printf("Crie um conjunto primeiro\n");
        return;
    }
    
    if(verificacao(m, cont)){
        return;
    }
       
    int a;
    if(matriz[m][n-1] != 0){
    	printf("Voce chegou no limite desse conjunto\n");
	return;
    }


    for(int i = busca_seq_recursiva(matriz[m], n, 0); i < n; i++){ //busca para identificar o primeiro 0
        printf("Caso queira parar, digite 0:\n");
        scanf("%i", &a);
        if (a == 0){
            break;
        }
        if (busca_seq_recursiva(matriz[m], n, a) != -1){
            printf("\nEsse numero ja pertence ao conjunto, digite novamente\n");
            i--;
            continue;
        }
        matriz[m][i] = a;
    }
    if (matriz[m][n-1] != 0){
        printf("Voce chegou no limite do conjunto.");
    }
    
}

void deletarConjunto(int m, int n, int matriz[m][n], int conj, int *cont){
    if (verificacao(conj, cont)){
        return;
    }
    int aux;
    for (int i = conj; i+1 < *cont; i++){
         for (int j = 0; j < n; j++){
            aux = matriz[i+1][j];
            matriz[i][j] = aux;
         }
    }
    for (int j = 0; j < n; j++){
            matriz[*cont-1][j] = 0;
         }
    //zerar a linha *cont-1
    *cont -= 1;  
}

int tamConj(int a[], int n){
	int i = 0;
	for(i = 0; i< n && a[i] != 0; i++);
	return i;
}

void uniaoConjuntos(int c1, int c2,int m, int n,int matriz[m][n],int *cont){
	if(verificacao(c1, cont)){
		return;
	}
	if(verificacao(c2, cont)){
		return;
	}
	
	int sizeC1, sizeC2;
	sizeC1 = tamConj(matriz[c1], n);
	sizeC2 = tamConj(matriz[c2], n);
	int sizeC3 = sizeC1 + sizeC2;
	for(int i = 0; i < sizeC2; i++){
		if(busca_seq_recursiva(matriz[c1], n, matriz[c2][i]) != -1){
			sizeC3--;
		}
	}
	if(sizeC3 > n){
		printf("A união desses dois conjuntos é maior que o tamanho maximo permitido\n");
		return;
	}
	int aux = *cont;
	inserirNovoConjunto(cont, m);
	if(aux == *cont){
		printf("Saida 1\n");
	       	return;
	}
	int i = 0;
	for(i = 0; i < sizeC1; i++){
		printf("Saida 2\n");
		matriz[*cont-1][i] = matriz[c1][i];
		printf("[%i] matriz[%i] = %i\n", *cont, i, matriz[*cont-1][i]);
	}
	for(int j = 0; j < sizeC2; j++){
		printf("Saida 4\n");
		if(busca_seq_recursiva(matriz[c1], n, matriz[c2][j]) == -1){
			printf("Saida 4.1\n");
			matriz[*cont-1][i] = matriz[c2][j];
			printf("[%i] matriz[%i] = %i\n", *cont, i, matriz[*cont-1][i]);
			i++;
		}
	}


}
void interseccaoConjutos(int c1, int c2,int m, int n, int matriz[m][n],int *cont){
   int aux = *cont;
    if (verificacao(c1, cont)){
        return;
    }
    if (verificacao(c2, cont)){
        return;
    }
    inserirNovoConjunto(cont, m);
    
    if(aux == *cont){
        printf("Nao eh possivel criar um novo conjunto\n");
        return;
    }
    for(int i = 0; i < n; i++){
        int chave = matriz[c2][i];
        if (busca_seq_recursiva(matriz[c1], n, chave) != -1){
            matriz[*cont-1][i] = chave;
        }   
    }
    
}

void mostrarUmConjunto(int m, int n, int matriz[m][n], int conj, int *cont){
    if (verificacao(conj, cont)){
        return;
    }
    printf("\nConjunto %i: ", conj);
    if (matriz[conj][0] == 0){
         printf("Vazio\n");
         return;
    }
    
    for (int i = 0; i < n; i++){
        if (matriz[conj][i] == 0){
            break;
        }
        printf("%i ", matriz[conj][i]);
    }
    
    printf("\n");
}

void mostrarConjuntos(int m, int n, int matriz[m][n], int *cont){
    printf("Há %d conjuntos: \n", *cont);
    for(int i = 0; i < *cont; i++){
        mostrarUmConjunto(m,n, matriz, i, cont);
        printf("\n");
    }
}

void buscaValor(int m, int n, int matriz[m][n], int chave, int *cont){
    printf("Conjuntos que contem o valor: ");
    int nenhum=0;
    for (int i = 0; i < *cont; i++){
        if (busca_seq_recursiva(matriz[i], n, chave) != -1 && chave != 0){
            printf("%i ", i);
            nenhum = 1;
        }else{
            if(nenhum == 0)
                nenhum = -1;
        }
    }
    if(nenhum == -1){
        printf("Nenhum conjunto contem esse numero");
        printf("\n");
    }
}

int verificacao(int linha, int *cont){
    if (linha+1 > *cont){
        printf("\nAlgum dos conjunto nao exite\n");
        return 1;
    }else{
        return 0;
    }
}

