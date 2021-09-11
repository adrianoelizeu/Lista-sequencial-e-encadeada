#define TRUE 1
#define FALSE 0
#define MAX 100

typedef struct inimigo {
  char nome[30];
  int vida;
  double ataque;
  struct inimigo* prox;
}Inimigo;
 
typedef struct lista{
  Inimigo* dados;
  int qtd;
}Lista;


Lista* criar();

 void deletar_lista(Lista* l);
 
 int criar_inimigos(Lista* l, char nome[30], int vida, double ataque);
 
 int tamanho_lista(Lista* l);

 int inimmigo_localizar(Lista* l, char _nome[30]);

 int matar_inimigo(Lista *l, char _nome[30]);

 void imprimir_inimigos(Lista *l);





