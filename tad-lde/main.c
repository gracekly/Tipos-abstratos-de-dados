//
// Created by grace on 17/11/2023.
//

#include "lde.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno {
  char nome[30];
  int idade;
  float nota;
} Aluno;

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

  Aluno *a, *b;
  int idade, opcao, inseriu, esvaziou, vazio, cont2, listaExiste, jaFoiEsvaziada;
  char nome[30];
  float nota;
  Aluno *aluno = NULL;
  DLList *lista;

  

  do {
    printf("------MENU------\n");
    printf("escolha uma opção:\n");
    printf("1 - crie uma lista\n");
    printf("2 - insira um elemento na lista\n");
    printf("3 - liste os elementos da lista\n");
    printf("4 - consulte um dos elementos da lista\n");
    printf("5 - remova da lista por char, int e float\n");
    printf("6 - esvazie a lista\n");
    printf("7 - destrua a lista\n");
    printf("0 - fechar o programa\n");

    scanf("%d", &opcao);

    switch (opcao) {

    case 0:
      printf("até mais!");
      break;

    case 1:
      if(listaExiste!=TRUE) {
        lista = dllCreate();
        if (lista != NULL) {
          printf("lista criado com sucesso!\n");
          listaExiste = TRUE;
        } else {
          printf("erro ao criar lista.\n");
        }
      }else {
        printf("lista ja existe\n");
      }
    
      break;

    case 2:
      
      if (listaExiste == TRUE) {
        a = (Aluno *)malloc(sizeof(Aluno));
        printf("para inserir o Aluno na lista, por favor, digite o "
               "nome:\n");
        scanf(" %29[^\n]", a->nome);
        printf("idade:\n");
        scanf("%d", &(a->idade));
        printf("nota:\n");
        scanf("%f", &(a->nota));

        void *elemento = (void *)a;

        if (lista != NULL) {
          if (lista->first != NULL) {
            inseriu = dllInsertAsLast(lista, elemento);
            if (inseriu == TRUE) {
              printf("Aluno inserido com sucesso!\n");
            } else {
              printf("erro ao inserir Aluno.\n");
            }
          } else {
            inseriu = dllInsertAsFirst(lista, elemento);
            if (inseriu == TRUE) {
              printf("Aluno inserido com sucesso!\n");
            
            } else {
              printf("erro ao inserir Aluno.\n");
            }
          }
        }
      } else {
        printf("impossivel inserir elemento numa lista inexistente\n");
      }
      

      break;

    case 3:
      if (listaExiste == TRUE) {
        printf("os elementos da lista são:\n");
        void **imprimir = listarElementos(lista);
        int contador = contarElementos(lista);

        if (lista == NULL || lista->first ==NULL)  {
          printf("nao ha elementos na lista ou a lista nao existe\n");
        } else {
          for (int i = 0; i < contador; i++) {
            b = (Aluno *)imprimir[i];
            printf("aluno %d:\n", i);
            printf("nome: %s\n", b->nome);
            printf("idade: %d\n", b->idade);
            printf("nota: %.2f\n", b->nota);
          }

        }
        
      }else {
        printf("lista nao existe\n");
      }

      break;

    case 4:
      if(listaExiste == TRUE) {
        printf("para consultar um dos Alunos inseridos na lista, por favor "
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

        aluno = (Aluno *)dllQuery(lista, nome_consulta, idade_consulta,
                                  nota_consulta, &buscar);
        if (aluno != NULL) {
          printf("o Aluno requisitado está na lista.\n");
        } else {
          printf("Aluno não encontrado.\n");
        }
      }else {
        printf("lista nao existe\n");
      }
     
      break;

    case 5:
      if(listaExiste == TRUE) {
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
        aluno = (Aluno *)dllRemoveSpec(lista, nome1, idade1, nota1, &buscar);
        if (aluno != NULL) {
          printf("Pessoa removida:\nNome: %s\nIdade: %d\nNota: %.2f", aluno->nome,
                 aluno->idade, aluno->nota);
        } else {
          printf("erro ao remover ou ao encontrar aluno.\n");
        }
      } else {
        printf("lista nao existe\n");
      }
      
      break;

    case 6:
      if (listaExiste == TRUE) {
        esvaziou = esvaziarLista(lista);
        if (esvaziou == TRUE) {
          
          printf("lista vazia!\n");
          
        } else {
          printf("erro ao esvaziar lista\n");
        }
      } else {
        printf("lista nao existe\n");
      }
     
      break;

    case 7:
      if (listaExiste == TRUE) {
        vazio = dllDestroy(lista);
        if (vazio == TRUE) {
          printf("lista destruida com sucesso!\n");
          listaExiste = FALSE;
        } else {
          printf("erro ao destruir lista\n");
        }
      } else {
        printf("lista nao existe\n");
      }
     
      break;


    default:
      printf("opção inválida!\n");
    }
  } while (opcao != 0);
  return 0;
}
