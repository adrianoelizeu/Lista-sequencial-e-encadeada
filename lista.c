#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Lista* criar(){
Lista* l = malloc(sizeof(Lista));
if (l != NULL)
 l->dados = NULL;
 l->qtd = 0;
return l; 
}

void deletar_lista(Lista* l){
  Inimigo * no = l->dados;
  while((no)!= NULL){
    Inimigo* aux = no->prox;
    free(no);
    no = aux;
  }
  free(l);
}

int criar_inimigos(Lista* l, char nome[30], int vida, double ataque){
  Inimigo* aux, * criar = malloc(sizeof(Inimigo));

  if(criar){
    strcpy (criar -> nome, nome); 
    criar ->vida = vida; 
    criar ->ataque = ataque;
    if(l->dados == NULL){ // Lista estiver vaizia, salvar no primiero 
      criar->prox=NULL;
      l->dados=criar;
    }
    else if(criar->vida < l->dados->vida){ 
      criar->prox = l->dados;
      l->dados = criar;
    }
    else{
      aux = l->dados;
      while(aux->prox && criar->vida > aux->prox->vida)
      aux = aux->prox;
      criar->prox = aux->prox;
      aux->prox = criar;
    }
    l->qtd++;
  }
  else {
  printf("Err - ao alocar\n");
  }
  return 0;
}

int tamanho_lista(Lista* l){
   if(l->dados==NULL){
    return printf("\nErr - Lista de vazia\n"); //retorna lista vazia 
   }
   else {
   return printf("TANANHO DA LISTA: %d\n", l->qtd);
 }
}

int inimmigo_localizar(Lista* l, char _nome[30]){ 
  Inimigo* atual = l->dados;
  int i = 0;

  while(atual !=NULL){
    if(!strcmp(_nome, atual->nome)){
      printf("\n         JORGADOR          \n");
      printf("|--------------------------\n" );
      printf("|  NOME: %s \n", atual->nome);
      printf("|  VIDA:  %d           <--    \n", atual->vida );
      printf("|ATAQUE: %0.1f           <--   \n", atual->ataque);
      printf("|--------------------------\n " );
    return i;
   
  }
  atual=atual->prox;
  i++;
  }
    return printf("\nErr - Inimigo não localizado\n");
  }

 int matar_inimigo(Lista *l, char _nome[30]){
   if (l->dados == NULL){
     return printf("\nErr - Lista de vazia\n");
   }

   Inimigo* aux, *remover = NULL;

   if(l->dados){
     if (!strcmp(_nome, l->dados->nome)){
       remover = l->dados;
       l->dados = remover->prox;
       l->qtd--;
      }
      else{
        aux = l->dados;
        while(aux->prox && aux->prox->nome != _nome){
         aux = aux->prox;
        if (aux->prox){
          remover = aux->prox;
          aux->prox = remover->prox;
          l->qtd--;
        }
      }
    }
  }
  return 0;
 }
   
 void imprimir_inimigos(Lista *l){
   if (l->dados == NULL){
     printf("\nErr - Lista de vazia\n");
      }
   Inimigo * atual = l->dados;

   while(atual !=NULL){
     printf("\n         JORGADOR          \n");
     printf("|--------------------------\n" );
     printf("|  NOME: %s \n", atual->nome);
     printf("|  VIDA:  %d           <--    \n", atual->vida );
     printf("|ATAQUE: %0.1f          <--   \n", atual->ataque);
     printf("|--------------------------\n " );
   atual = atual->prox;
   printf("\n\n");
 }
 }

