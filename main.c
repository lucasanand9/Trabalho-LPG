#include <stdio.h>
#include <string.h>
#include "toolKit.h"

//#define M 10
//#define N 8

void menu();
void inserirNovoConjunto(int cont, int m); //1
void inserirDados(int m, int n, int matriz[m][n], int cont);//2
void deletarConjunto(int m, int n, int matriz[m][n], int conj, int cont);//3
void uniaoConjuntos(int c1, int c2,int m, int n,int matriz[m][n],int cont);//4
void interseccaoConjutos(int c1, int c2,int m, int n,int matriz[m][n],int cont);//5
void mostrarUmConjunto(int m, int n, int matriz[m][n], int conj, int cont);//6
void mostrarConjuntos(int m, int n, int matriz[m][n], int cont);//7
void buscaValor(int m, int n, int matriz[m][n], int chave, int cont);//8
int verificacao(int linha,int cont);

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
        menu();
        scanf("%i", &Imenu);
        switch (Imenu){
            case 1:
                //criar novo conjunto
                inserirNovoConjunto(cont, M);
                printf("\nHá %d conjunto(s) registrado(s).\n",cont);
            break;
            case 2:
                //inserir conjunto
                printf("Em qual conjunto voce quer inserir valores?\n");
                scanf("%i", &conj);
                inserirDados(conj, N, m, cont);
            break;
            case 3:
                //remover conjunto
                printf("Qual conjunto voce quer remover?\n");
                scanf("%i", &conj);
                deletarConjunto(M,N,m,conj,cont);
            break;
            case 4:
                //unir
                printf("Digite quais conjuntos voce quer que sejam unidos:\n");
                scanf("%i%i", &c1, &c2);
                uniaoConjuntos(c1, c2, M,N,m, cont);
            break;
            case 5:
                //intersecçao
                printf("Digite quais conjuntos voce quer que sejam interseccionados:\n");
                scanf("%i%i", &c1, &c2);
                interseccaoConjutos(c1,c2,M,N,m,cont);
            break;
            case 6:
                //mostrar 1 conjunto
                printf("Digite qual conjunto voce quer visualizar:\n");
                scanf("%i", &conj);
                mostrarUmConjunto(M, N, m, conj, cont);
            break;
            case 7:
                //mostrar varios conjuntos
                mostrarConjuntos(cont, N, m, cont);
            break;
            case 8:
                //busca valor
                printf("Digite qual valor voce quer buscar dentro da matriz:\n");
                int chave;
                scanf("%i", &chave);
                buscaValor(M, N, m, chave, cont);
            break;
        }
        Imenu = -1;
    }while (Imenu != 0);

    // uniaoConjuntos();
    // menu();
    // scanf("%i", &Imenu);
    //fazer o switch no final!
}

void menu(){
    printf("\n================================================\n");
    printf("Qual sua escolha para hoje?\n");
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

void inserirNovoConjunto(int cont,int m){
    if(cont == m){
        printf("\nNao eh possivel adicionar mais conjuntos :(\nCaso queira criar um novo conjunto, exclua algum que voce nao esta mais ultilizando.\n");
        return;
    }
    cont ++;
}

void inserirDados(int m, int n, int matriz[m][n], int cont){
    if (cont == 0){
        printf("Crie um conjunto primeiro\n");
        return;
    }
    
    if(verificacao(m, cont)){
        return;
    }
       
    int a;

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
    printf("Voce chegou no limite maximo do conjunto");
}

void deletarConjunto(int m, int n, int matriz[m][n], int conj, int cont){
    if (verificacao(conj, cont)){
        return;
    }
    int aux;
    for (int i = conj; i <= cont; i++){
         for (int j = 0; j < n; j++){
            aux = matriz[i+1][j];
            matriz[i][j] = aux;
         }
    }
    cont--;  
}

void uniaoConjuntos(int c1, int c2,int m, int n,int matriz[m][n],int cont){
    int aux = cont;
    if (verificacao(c1, cont)){
        printf("Conjunto: %i", c1);
        return;
    }
    if (verificacao(c2, cont)){
        printf("Conjunto: %i", c2);
        return;
    }
    inserirNovoConjunto(cont, m);
    
    if(aux == cont){
        return;
    }
    int sizeC1, sizeC2, sizeC3;
        if ( busca_seq_recursiva(matriz[c1], n, 0) == -1){
                sizeC1 = n;
            }else{
                sizeC2 = busca_seq_recursiva(matriz[c1], n, 0);
            }
            
            if ( busca_seq_recursiva(matriz[c2], n, 0) == -1){
                sizeC2 = n;
            }else{
                sizeC2 = busca_seq_recursiva(matriz[c2], n, 0);
            }
        
        int c3 = cont;
        int vetor_criado[sizeC1 + sizeC2]; //vetor novo
        int i;
        for(i=0;i<n;i++){
            vetor_criado[i] = matriz[c1][i];
        }

        for(int j=0;j<n;j++){
            if (busca_seq_recursiva(matriz[c1], n, matriz[c2][j]) != -1){ //n achar repetido
                vetor_criado[j] = matriz[c2][j+sizeC1];
            }else{
                j = j - 1;
            }
        }

    if ( busca_seq_recursiva(vetor_criado, n, 0) == -1){
                sizeC3 = n;
            }else{
                sizeC3 = busca_seq_recursiva(vetor_criado, n, 0);
            }
    for(int i=0;i<n;i++){ //verificacao se vetor cabe depois de apagar os repetidos
        if(sizeC3 <= n){
            for(int j = 0; j < n; j++){
                matriz[c3][j] = vetor_criado[j];
            }
        }
        else{
            printf("A uniao dos vetores nao eh permitida porque extrapola a quantidade de colunas da matriz!");
        }
    }
}

void interseccaoConjutos(int c1, int c2,int m, int n, int matriz[m][n],int cont){
   int aux = cont;
    if (verificacao(c1, cont)){
        printf("Conjunto: %i", c1);
        return;
    }
    if (verificacao(c2, cont)){
        printf("Conjunto: %i", c2);
        return;
    }
    inserirNovoConjunto(cont, m);
    
    if(aux == cont){
        return;
    }

    for(int i = 0; i < n; i++){
        if (busca_seq_recursiva(matriz[c1], n, matriz[c2][i]) != -1){
            matriz[cont][i] = matriz[c2][i];
        }   
    }
    
}

void mostrarUmConjunto(int m, int n, int matriz[m][n], int conj, int cont){
    if (verificacao(conj, cont)){
        return;
    }
    printf("\nConjunto %i: ", conj);
    mostra_vetor(matriz[conj],busca_seq_recursiva(matriz[conj], n, 0),"");
}

void mostrarConjuntos(int m, int n, int matriz[m][n], int cont){
    printf("Há %d conjuntos: \n", cont);
    for(int i = 0; i < cont; i++){
        printf("%d",i);
        if(matriz[i][0] == 0)
            printf(" = vazio \n");
        else{
            mostra_vetor(matriz[i],busca_seq_recursiva(matriz[i], n, 0)," = ");
            printf("\n");
        }
    }
}

void buscaValor(int m, int n, int matriz[m][n], int chave, int cont){
    printf("Conjuntos que contem o valor:\n");
    for (int i = 0; i < cont; i++){
        if (busca_seq_recursiva(matriz[i], n, chave) != -1){
            printf("%i", i);
        }
    }
}

int verificacao(int linha, int cont){
    if (linha+1 > cont){
        printf("\nInfelizmente esse conjunto nao existe :(\n");
        return 1;
    }else{
        return 0;
    }
}

