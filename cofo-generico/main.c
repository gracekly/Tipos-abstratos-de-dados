//
// Created by grace on 17/09/2023.
//

#include "cofo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscar(void *item, void *nome, void *idade, void *nota) {
  Aluno *aluno = (Aluno *)item;
  int comparacao = strcmp((char *)nome, aluno->nome);
  if (comparacao == TRUE) {
    if (aluno->idade == *(int *)idade && aluno->nota == *(float *)nota) {
      return TRUE;
    }
  }
  return FALSE;
}
int main() {

  int opcao, max_itens, idade, indice, esvaziou, vazio;
  Aluno *a, *b;
  gCofo *cofo;
  char nome[30];
  float nota;
  Aluno *aluno = NULL;

  do {
    printf("------MENU------\n");
    printf("escolha uma opção:\n");
    printf("1 - crie uma coleção\n");
    printf("2 - insira um elemento na coleção\n");
    printf("3 - liste os elementos da coleção\n");
    printf("4 - consulte um dos elementos da coleção\n");
    printf("5 - remova do cofo por char, int e float\n");
    printf("6 - remova do cofo opor indice\n");
    printf("7 - esvazie a coleção\n");
    printf("8 - destrua o cofo\n");
    printf("0 - fechar o programa\n");

    scanf("%d", &opcao);

    switch (opcao) {

    case 0:
      printf("até mais!");
      break;

    case 1:
      printf("quantos elementos será a capacidade do cofo?\n");
      scanf("%d", &max_itens);
      cofo = criarCofo(max_itens);
      if (cofo != NULL) {
        printf("cofo criado com sucesso!\n");
      } else {
        printf("erro ao criar cofo.\n");
      }
      break;

    case 2:

      a = (Aluno *)malloc(sizeof(Aluno));
      printf("para inserir o Aluno na coleçao, por favor, digite o "
             "nome:\n");
      scanf(" %29[^\n]", a->nome);
      printf("idade:\n");
      scanf("%d", &(a->idade));
      printf("nota:\n");
      scanf("%f", &(a->nota));

      void *elemento = (void *)a;

      int inseriu = inserirNoCofo(cofo, elemento);
      if (inseriu == TRUE) {
        printf("Aluno inserido com sucesso!\n");
      } else {
        printf("erro ao inserir Aluno.\n");
      }

      break;

    case 3:
      printf("os elementos do cofo são:\n");
      void **imprimir = listarElementos(cofo);

      for (int i = 0; i < cofo->num_itens; i++) {
        b = (Aluno *)imprimir[i];
        printf("aluno %d:\n", i);
        printf("nome: %s\n", b->nome);
        printf("idade: %d\n", b->idade);
        printf("nota: %.2f\n", b->nota);
      }

      break;

    case 4:
      printf("para consultar um dos Alunos inseridos no cofo, por favor "
             "insira:\n");
      printf("nome:\n");
      scanf(" %29[^\n]", nome);
      printf("idade:\n");
      scanf("%d", &idade);
      printf("nota:\n");
      scanf("%f", &nota);

      void *nome_consulta = (void *)nome;
      void *idade_consulta = (void *)&idade;
      void *nota_consulta = (void *)&nota;

      aluno = (Aluno *)consultarElemento(cofo, nome_consulta, idade_consulta,
                                         nota_consulta, &buscar);
      if (aluno != NULL) {
        printf("o Aluno requisitado está no cofo.\n");
      } else {
        printf("Aluno não encontrado.\n");
      }
      break;

    case 5:

      printf("para remover um dos elementos da coleção, por favor, "
             "insira:\n");
      printf("nome:\n");
      scanf(" %29[^\n]", nome);
      printf("idade:\n");
      scanf("%d", &idade);
      printf("nota:\n");
      scanf("%f", &nota);
      void *nome1 = (void *)nome;
      void *idade1 = (void *)&idade;
      void *nota1 = (void *)&nota;
      aluno = (Aluno *)removerDoCofo(cofo, nome1, idade1, nota1, &buscar);
      if (aluno != NULL) {
        printf("Pessoa removida:\nNome: %s\nIdade: %d\nNota: %.2f", aluno->nome,
               aluno->idade, aluno->nota);
      } else {
        printf("erro ao remover ou ao encontrar aluno.\n");
      }
      break;

    case 6:

      printf("qual elemento você gostaria de remover do cofo? (1, 2, 3,...)\n");
      scanf("%d", &indice);

      void *removido = removerPorIndice(cofo, indice);

      if (removido != NULL) {
        Aluno *c = (Aluno *)removido;

        printf("elemento removido:\n");
        printf("nome: %s\n", c->nome);
        printf("idade: %d\n", c->idade);
        printf("nota: %.2f\n", c->nota);
      } else {
        printf("erro ao remover Aluno pelo índice.\n");
      }
      break;

    case 7:

      esvaziou = esvaziarCofo(cofo);
      if (esvaziou == TRUE) {
        printf("cofo esvaziado com sucesso!\n");
      } else {
        printf("erro ao esvaziar cofo\n");
      }
      break;

    case 8:
      vazio = destruirCofo(cofo);
      if (vazio == TRUE) {
        printf("cofo destruido com sucesso!\n");
      } else {
        printf("erro ao destruir cofo\n");
      }
      break;

    default:
      printf("opção inválida!\n");
    }
  } while (opcao != 0);
  return 0;
}
