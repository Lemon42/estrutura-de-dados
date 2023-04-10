// http://wiki.icmc.usp.br/images/d/db/AulaListaEncadeada.pdf
// https://gist.github.com/marcoscastro/81fb7cb3c5c2b7370bf5
#include <stdio.h>
#include <stdlib.h>

struct lista {
  int cod;
  struct lista *prox;
};
typedef struct lista Lista;

Lista *Primeiro;
Lista *Ultimo;

void criarLista() {
  Lista *aux;
  aux = (Lista*)malloc(sizeof(Lista));
  Primeiro = aux;
  Ultimo = Primeiro;
}

void inserir(int x) {
  Lista *novo;
  novo = (Lista*)malloc(sizeof(Lista));
  novo->cod = x;
  
  Ultimo->prox = novo;
  Ultimo = novo;
  novo->prox = NULL;
}

void imprime() {
  Lista *aux;
  aux = Primeiro->prox;
  while (aux != NULL) {
    printf("Item = %d\n", aux->cod);
    aux = aux->prox;
  }
}

int main(void) { 
  criarLista();
  inserir(45);
  inserir(4225);
  inserir(453);
  inserir(145);
  inserir(345);
  inserir(425);
  imprime();
  return 0;
}