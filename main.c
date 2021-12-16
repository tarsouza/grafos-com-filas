#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "filas.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    Matriz m1;

	Pilha p1;
    inicializa_pilha( &p1, 32 );
	
	empilha( &p1, 1);

    carrega_matriz_arquivo( "arquivotexto.txt", &m1 );
    mostra_matriz( m1 );

    int *vs = aloca_vetor_zerado(m1.col);
    int *vant = aloca_vetor_antecessor(m1.col);
    
	int ini;
	printf("Digite o vertice inicial: ");
	scanf("%i", &ini);
	
	int fin;
	printf("Digite o vertice final: ");
	scanf("%i", &fin);


	Fila f1;
	inicializa_fila( &f1 );
	mostra_fila( f1 );
	
	inserir( &f1, 2 );
	mostra_fila( f1 );
	
	int x;
	remover( &f1, &x );
	printf("Valor removido: %d\n\n", x );
	mostra_fila( f1 );
	
	mostra_pilha (p1);

    desaloca_pilha( &p1 );
	
    return 0; 
}
