#include <stdio.h>
#include "trabalho.h"

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
}

