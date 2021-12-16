#define ERRO_COORD_INVALIDA -1		// MATRIZ

#define MAX 4						//
#define ERRO_FILA_VAZIA -1			//   FILAS
#define ERRO_FILA_CHEIA -2			//

#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2

typedef struct{
    int **dadosMatriz;
    int lin, col;
    int vs[];
}Matriz;

typedef struct{
   int dados[MAX]; // dados da fila 
   int inicio;     // índice do início da fila
   int n;          // qtd. de elementos da fila
} Fila;

typedef struct{
   int *dadosPilha;        // dados da pilha 
   int topo;        // indica o índice do topo
   int capacidade;    // capacidade do vetor alocado
} Pilha;

void inicializa_fila ( Fila *p );
int fila_vazia ( Fila f );
int fila_cheia ( Fila f );
int inserir ( Fila *p, int info );
int remover ( Fila *p, int *info );
void mostra_fila ( Fila f );

void inicializa_matriz( Matriz *p, int l, int c );                //
void mostra_matriz( Matriz m );                                    //
int set_matriz( Matriz *p, int i, int j, int valor );            //        MATRIZ
int get_matriz( Matriz m, int i, int j, int *p_valor );            //
int compara_matrizes( Matriz m1, Matriz m2 );                    //
int carrega_matriz_arquivo( char *nome_arq, Matriz *p );        //

int *aloca_vetor_zerado (int n);
int *aloca_vetor_antecessor (int n);


void inicializa_pilha ( Pilha *p, int c );        //
int pilha_vazia ( Pilha p );                    //
int pilha_cheia ( Pilha p );                    //
int empilha ( Pilha *p, int info );                //                PILHA
int desempilha ( Pilha *p, int *info );            //
int le_topo ( Pilha p, int *info );                //
void mostra_pilha ( Pilha p );                    //
void desaloca_pilha( Pilha *p );                //
