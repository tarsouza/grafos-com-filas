#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "filas.h"
#include <stdbool.h>

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    
    Matriz m1;
    carrega_matriz_arquivo( "arquivotexto.txt", &m1 );		// importando matriz 8x8 que está em .txt
    mostra_matriz( m1 );

	int ini;
	printf("Digite o vertice inicial: ");
	scanf("%i", &ini);
	
	int fin;
	printf("Digite o vertice final: ");
	scanf("%i", &fin);

    int *vs = aloca_vetor_zerado(m1.col);
    int *vant = aloca_vetor_antecessor(m1.col);

	Fila f1;
	inicializa_fila( &f1 );
	mostra_fila( f1 );

	vs[ini]= 1;

	inserir( &f1, ini );
	
	int achou = 0;
	int i, x;
	int dimensao = 8;

		while(fila_vazia(f1) != 1 && achou == 0){
			if(x==fin){
				achou = 1;
			} else {
				for (i = 0; i < dimensao; i++){
					if(vs[i]==0){
						
						vs[i]= 1;
						vant[i]= x;
						inserir( &f1, i );

					}
				}
			}
		} if( achou == 1){
			Pilha p1;
    		inicializa_pilha( &p1, 32 );
    		
    		while( x!= 0){
    			empilha(&p1, x);
    			x = vant[x];
			}while(pilha_vazia(p1) != -1){
				desempilha(&p1, x);
				printf("%i", x);
			}
		}else{
			printf("B Não é alcançável a partir de A");
		}
	
    return 0; 
}
