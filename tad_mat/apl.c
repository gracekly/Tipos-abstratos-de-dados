//grace kelly santos
#include "matriz.h"
#include <stdio.h>

int main() {

  int opcao, linhasA, colunasA, linhasB, colunasB;

  do {

    printf("------ MENU ------\n");
    printf("escolha uma opção\n");
    printf("1 - cria matriz A\n");
    printf("2 - cria matriz B\n");
    printf("3 - inserir dados na matriz A\n");
    printf("4 - inserir dados na matriz B\n");
    printf("5 - calcular a transposta da matriz A e imprimir o resultado\n");
    printf("6 - calcular a transposta da matriz B e imprimir o resultado\n");
    printf("7 - multiplica matriz A pela matriz B (se possível)\n");
    printf("8 - destruir a matriz A\n");
    printf("9 - destruir a matriz B\n");
    printf("10 - destroi matriz transposta A\n");
    printf("11 - destroi matriz transposta B\n");

    printf("0 - fechar o programa\n");
    scanf("%d", &opcao);

    switch (opcao) {

    case 0:
      printf("até mais!");
      break;

    case 1:
      printf("digite o numero de linhas e colunas da matriz A: \n");
      scanf("%d %d", &linhasA, &colunasA);
      Matriz *A = criaMatriz(linhasA, colunasA);
      break;

    case 2:
      printf("digite o numero de linhas e colunas da matriz B: \n");
      scanf("%d %d", &linhasB, &colunasB);
      Matriz *B = criaMatriz(linhasB, colunasB);
      break;

    case 3:
      insereElemMatriz(A);
      break;

    case 4:
      insereElemMatriz(B);
      break;

    case 5:
      printf("a matriz transposta é:\n\n ");
      Matriz *transposta_A = calculaTransposta(A);
      for (int i = 0; i < transposta_A->linha; i++) {
        for (int j = 0; j < transposta_A->coluna; j++) {
          printf("%d\t", transposta_A->vet[i * transposta_A->coluna + j]);
        }
        printf("\n");
      }
      break;

    case 6:
      printf("a matriz transposta é: \n\n ");
      Matriz *transposta_B = calculaTransposta(B);
      for (int i = 0; i < transposta_B->linha; i++) {
        for (int j = 0; j < transposta_B->coluna; j++) {
          printf("%d\t", transposta_B->vet[i * transposta_B->coluna + j]);
        }
      }
      break;

    case 7:
      printf("o resultado da multiplicação entre as matrizes A e B é:\n");
      Matriz *c = multMatriz(A, B);
      for (int i = 0; i < c->linha; i++) {
        for (int j = 0; j < c->coluna; j++) {
          printf("%d\t", c->vet[i * c->coluna + j]);
        }
        printf("\n");
      }

      break;

    case 8:
      destroiMatriz(A);

      break;

    case 9:
      destroiMatriz(B);

      break;

    case 10:
      destroiMatriz(transposta_A);
      break;

    case 11:
      destroiMatriz(transposta_B);
      break;

    default:
      printf("opção inválida!\n");
    }

  } while (opcao != 0);

  return 0;
}