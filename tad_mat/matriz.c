//grace kelly santos
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

Matriz *criaMatriz(int m, int n) {

  Matriz *ma = (Matriz *)malloc(sizeof(Matriz)); // alocou... testou...

  if (ma != NULL) {

    ma->linha = m;
    ma->coluna = n;
    ma->vet = (int *)malloc(sizeof(int) * m * n);

    if (ma->vet != NULL) {
      return ma;
    }
    free(ma);
  }

  return NULL;
}
//-------------------------------------------------------------------------------

void insereElemMatriz(Matriz *mat) {
  if (mat != NULL) {
    for (int i = 0; i < mat->linha; i++) {
      for (int j = 0; j < mat->coluna; j++) {
        printf("digite o elemento da posição linha[%d] e coluna[%d]: ", i, j);
        scanf("%d", &(mat->vet[i * mat->coluna + j]));
      }
    }
    printf("matriz preenchida com sucesso!\n");
  } else {
    printf("erro ao preencher matriz\n");
  }
}
//------------------------------------------------------------------------------------

Matriz *multMatriz(Matriz *mat_a, Matriz *mat_b) {
  if (mat_a != NULL && mat_b != NULL) {
    if (mat_a->coluna ==
        mat_b->linha) // coluna da primeira deve ser igual a linha da segunda
    {
      Matriz *mat_result = criaMatriz(
          mat_a->linha,
          mat_b->coluna); // o resultado da multiplicação sera uma matriz com as
                          // quants de linhas da primeira e colunas da segunda

      for (int i = 0; i < mat_a->linha; i++) {
        for (int j = 0; j < mat_b->coluna; j++) {
          mat_result->vet[i * mat_result->coluna + j] = 0;

          for (int k = 0; k < mat_a->coluna; k++) {
            mat_result->vet[i * mat_result->coluna + j] +=
                (mat_a->vet[i * mat_a->coluna + k]) *
                (mat_b->vet[k * mat_b->coluna + j]);
          }
        }
      }
      return mat_result;
    }
  }
  return NULL;
}
//----------------------------------------------------------------------------------------------------------------------------

Matriz *calculaTransposta(Matriz *matriz) {
  if (matriz != NULL) {
    int linha = matriz->coluna;
    int coluna = matriz->linha;

    Matriz *transposta = criaMatriz(linha, coluna);

    if (transposta != NULL) {
      for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
          // Ajuste dos índices para a matriz transposta
          transposta->vet[i * coluna + j] = matriz->vet[j * linha + i];
        }
      }
    }
    return transposta;
  }
  return NULL;
}

//-----------------------------------------------------------------------------------------------------------

void destroiMatriz(Matriz *matrix) {

  if (matrix != NULL) {
    free(matrix->vet);
    free(matrix);
    printf("matriz deletada com sucesso!");
  } else {
    printf("erro ao deletar matriz.");
  }
}