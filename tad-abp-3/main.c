//grace kelly barros araujo dos santos
#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

int cmp(void *data, void *data2) {
  int *newdata = (int *)data;
  int *newdata2 = (int *)data2;

  //-------------------------------------------------------

  if (*newdata < *newdata2) {
    return -1;
  } else if (*newdata > *newdata2) {
    return 1;
  } else {
    return 0;
  }
}

//---------------------------------------------------------

void visit(void *data) {
  Aluno *a = (Aluno *)data;
  printf("elemento: %d\n", a->matricula);
}

//--------------------------------------------------------------

int getIntegerInput() {
    int num;
    while (scanf("%d", &num) != 1) {
        printf("Entrada inválida. Por favor, digite um número inteiro.\n");
        while(getchar() != '\n'); 
    }
    return num;
}

//--------------------------------------------------------------

int main(void) {

  int opcao, treeCreated = FALSE, esvaziou = FALSE, destruiu = FALSE;
  TNode *raiz;
  Aluno *a;

  do {
    printf("\n------MENU------\n");
    printf("escolha uma opcao:\n");
    printf("1 - crie uma arvore\n");
    printf("2 - insira um elemento na arvore\n");
    printf("3 - remova um elemento da arvore\n");
    printf("4 - consulte um dos elementos da arvore\n");
    printf("5 - liste os elementos da arvore\n");
    printf("6 - esvazie a arvore\n");
    printf("7 - destrua a arvore\n");
    printf("0 - fechar o programa\n");

    opcao = getIntegerInput();
    
    switch (opcao) {

    case 0:
      printf("ate mais!");
      break;

    case 1:
      if (treeCreated != TRUE) {
        treeCreated = abpCreate(raiz);

        if (treeCreated == TRUE) {
          printf("ávore criada com sucesso!\n");
        } else {
          printf("erro ao criar árvore.");
        }

      } else {
        printf("árvore já existe.");
      }
      break;

    case 2:
      if (treeCreated == TRUE) {
        a = (Aluno *)malloc(sizeof(Aluno));

        if (a != NULL) {
          printf("digite o elemento para inserir na arvore:\n");

          if (scanf("%d", &(a->matricula)) == 1) {
            printf("lido com sucesso!\n");

            raiz = abpInsert(raiz, (void *)a, cmp);

            if (raiz != NULL) {
              printf("elemento inserido com sucesso!\n");
              esvaziou = FALSE;

            } else {
              printf("falha ao inserir o elemento.\n");
            }
          } else {
            while (getchar() != '\n')
              ;
            printf("erro ao realizar leitura. certifique-se de que voce "
                   "inseriu um numero inteiro.\n");
          }
        }
      } else {
        printf("falha ao inserir o elemento.\n");
      }
      break;

    case 3:
      if (treeCreated == TRUE) {
        if (raiz != NULL) {
          Aluno *key = (Aluno *)malloc(sizeof(Aluno));

          if (key != NULL) {
            printf("digite qual elemento voce gostaria de remover:\n");

            if (scanf("%d", &key->matricula) == 1) {
              printf("lido com sucesso!\n");

              void *data;
              Aluno *a = (Aluno *)abpQuery(raiz, (void *)&key->matricula, cmp);

              if (a != NULL) {
                raiz = abpRemove(raiz, (void *)&key->matricula, cmp, &data);
                printf("elemento removido com sucesso!\n");

              } else {
                printf("elemento nao encontrado.\n");
              }
            } else {
              while (getchar() != '\n')
                ;
              printf("erro ao realizar leitura. certifique-se de que voce "
                     "inseriu um numero inteiro.\n");
            }
          }
        } else {
          printf("árvore vazia.\n");
        }
      } else {
        printf("árvore nao existe.\n");
      }
      break;

    case 4:
      if (treeCreated == TRUE) {
        if (raiz != NULL) {
          Aluno *key = (Aluno *)malloc(sizeof(Aluno));

          if (key != NULL) {
            printf("digite qual elemento voce gostaria de consultar:\n");

            if (scanf("%d", &key->matricula) == 1) {
              printf("lido com sucesso!\n");

              void *data;
              Aluno *a = (Aluno *)abpQuery(raiz, (void *)&key->matricula, cmp);

              if (a != NULL) {

                printf("elemento está na árvore!\n");

              } else {
                printf("elemento nao encontrado.\n");
              }
            } else {
              while (getchar() != '\n')
                ;
              printf("erro ao realizar leitura. certifique-se de que voce "
                     "inseriu um numero inteiro.\n");
            }
          }

        } else {
          printf("árvore vazia.\n");
        }
      } else {
        printf("árvore nao existe.\n");
      }

      break;

    case 5:
      if (treeCreated == TRUE) {
        if (raiz != NULL) {
          simetrico(raiz, visit);
        } else {
          printf("árvore vazia.\n");
        }

      } else {
        printf("árvore nao existe.\n");
      }

      break;

    case 6:
      if (treeCreated == TRUE) {
        if (raiz != NULL) {
          esvaziou = abpEsvaziar(&raiz); // Pass the address of raiz pointer

          if (esvaziou == TRUE) {
            printf("arvore esvaziada com sucesso!\n");

          } else {
            printf("erro ao esvaziar a arvore.\n");
          }
        } else {
          printf("a arvore esta vazia.\n");
        }
      } else {
        printf("árvore nao existe.\n");
      }

      break;

    case 7:
      if (treeCreated == TRUE) {
        destruiu = abpDestroy(raiz);

        if (destruiu == TRUE) {

          printf("arvore destruida com sucesso!\n");
          treeCreated = FALSE;
        } else {
          printf("erro ao destruir arvore.\n");
        }
      } else {
        printf("árvore nao existe.\n");
      }

      break;

    default:
      printf("opcao invalida!\n");
    }
  }

  while (opcao != 0);

  return 0;
}