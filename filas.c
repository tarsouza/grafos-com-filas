#include <stdio.h>
#include <stdlib.h>
#include "filas.h"

void inicializa_matriz( Matriz *p, int l, int c ){
    p->lin = l;
    p->col = c;
    
    p->dadosMatriz = malloc( sizeof(int *) * l );
    int i, j;
    for( i = 0 ; i < l ; i++ ){
        p->dadosMatriz[i] = calloc(c, sizeof(int) );
        
    }
}

void mostra_matriz( Matriz m ){
    printf("Dados da matriz %dx%d:\n", m.lin, m.col);
    int i, j;
    for( i = 0 ; i < m.lin ; i++ ){
        for( j = 0 ; j < m.col ; j++ )
            printf("%4d ", m.dadosMatriz[i][j]);
        printf("\n");
    }
    printf("\n");
}

int set_matriz( Matriz *p, int i, int j, int valor ){
    if( i >= p->lin || j >= p->col )
        return ERRO_COORD_INVALIDA;
    
    p->dadosMatriz[i][j] = valor;
    
    return 1; // Sucesso.    
}

int get_matriz( Matriz m, int i, int j, int *p_valor ){
    if( i >= m.lin || j >= m.col )
        return ERRO_COORD_INVALIDA;
    
    *p_valor = m.dadosMatriz[i][j];
    return 1; // Sucesso.    
}

int compara_matrizes( Matriz m1, Matriz m2 ){
    if( m1.lin != m2.lin || m1.col != m2.col )
        return 0; // Falso, s?o diferentes!
    
    int i, j;
    for( i = 0 ; i < m1.lin ; i++ )
        for( j = 0 ; j < m1.col ; j++ )
            if( m1.dadosMatriz[i][j] != m2.dadosMatriz[i][j] )
                return 0; // Falso, s?o diferentes!
                
    return 1; // Verdadeiro, s?o iguais!
}

int carrega_matriz_arquivo( char *nome_arq, Matriz *p ){
    FILE *f = fopen( nome_arq, "rt" );
    if( f == NULL )
        return 0; // 0 (falso) --> erro no arquivo ou arquivo n?o existe!
        
    int dim, i, j;
    fscanf( f, "%d", &dim );
    
    inicializa_matriz( p, dim, dim);
    
    for( i = 0 ; i < dim ; i++ )
        for( j = 0 ; j < dim ; j++ ){
            int valor;
            fscanf( f, "%d", &valor);
            set_matriz( p , i, j, valor );
        }
    
    fclose( f );
    return 1; // 1 (verdadeiro) --> carga realizada!
}

    int *aloca_vetor_zerado (int n){
            
        int * p = calloc (n, sizeof(int));    
        return p;
}

    int *aloca_vetor_antecessor (int n){
            
        int * p = calloc (n, sizeof(int));    
        return p;
}



// 				FILAS




void inicializa_fila ( Fila *p ){
	p->inicio = 0;
	p->n = 0;
}

int fila_vazia ( Fila f ) {
	return f.n == 0;
}

int fila_cheia ( Fila f ) {
	return f.n == MAX;
}

int inserir ( Fila *p, int info ){
	if( fila_cheia ( *p ) )
		return ERRO_FILA_CHEIA;
	
	int fim = ( p->inicio + p->n ) % MAX;
	p->dados[fim] = info;
	p->n++;
	return 1; // Sucesso
}

int remover ( Fila *p, int *info ){
	if( fila_vazia ( *p ) )
		return ERRO_FILA_VAZIA;
	
	*info = p->dados[p->inicio];
	p->inicio = (p->inicio + 1) % MAX;
	p->n--;
	return 1; // Sucesso
}

void mostra_fila ( Fila f ){
	if( fila_vazia ( f ) )
		printf("Fila vazia!\n");
	else{
		printf("Dados da fila:\n");
		int i, cont;

		for( cont = 0, i = f.inicio ; cont < f.n ; cont++, i = (i + 1) % MAX )
			printf("[%d] %d\n", i, f.dados[i]);
		
	}
	printf("\n");
}

	/*                 PILHAS
	*/
void inicializa_pilha ( Pilha *p, int c ){
    p->dadosPilha = malloc( sizeof(int) * c );
    p->capacidade = c;
    p->topo = -1;
}

int pilha_vazia ( Pilha p ) {
    return p.topo == -1;
}

int pilha_cheia ( Pilha p ) {
    return p.topo == p.capacidade - 1;
}

int empilha ( Pilha *p, int info ) {
    if( pilha_cheia ( *p ) )
        return ERRO_PILHA_CHEIA;

    p->topo++;
    p->dadosPilha[p->topo] = info;
    return 1; // Sucesso
}

int desempilha ( Pilha *p, int *info ) {
    if ( pilha_vazia ( *p ) )
        return ERRO_PILHA_VAZIA;

    *info = p->dadosPilha[p->topo];
    p->topo--;
    return 1; // Sucesso
}

int le_topo ( Pilha p, int *info ) {
   if ( pilha_vazia( p ) )
      return ERRO_PILHA_VAZIA;

   *info = p.dadosPilha[p.topo];
   return 1; // Sucesso
}

void mostra_pilha ( Pilha p ) {
    if( pilha_vazia ( p ) )
        printf("Pilha vazia!\n");
    else{
        printf("Dados da Pilha:\n");
        int i;
        for( i=0 ; i <= p.topo ; i++)
            printf("%d\n", p.dadosPilha[i]);
   }
}

void desaloca_pilha( Pilha *p ){
    
    free( p->dadosPilha );
}
