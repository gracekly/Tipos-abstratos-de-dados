//
// Created by grace on 15/09/2023.
//

#ifndef COFO_GENERICO_H
#define COFO_GENERICO_H

#define FALSE 1
#define TRUE 0
#define DEFAULT -1

typedef struct aluno{

  char nome[30];
  int idade;
  float nota;

} Aluno;

typedef struct gcofo {
  int num_itens;
  int max_itens;
  int current;
  void **item;
}gCofo;

typedef struct gcofo gCofo;

gCofo* criarCofo(int max_itens);

int inserirNoCofo(gCofo *cofo, void* item);

void *removerDoCofo(gCofo *cofo, void* chave1, void* chave2, void* chave3, int (*cmp)(void*, void*, void*, void*));

void *consultarElemento(gCofo *cofo, void* nome, void* idade, void* nota, int (*cmp) (void*, void*, void*, void*));

void **listarElementos(gCofo *cofo);

int destruirCofo(gCofo *cofo);

int esvaziarCofo(gCofo *cofo);

void* removerPorIndice(gCofo *cofo, int i);


#endif //COFO_GENERICO_H

