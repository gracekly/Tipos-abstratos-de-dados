//grace kelly santos

#ifndef MATRIZ_H // se coluna estiver definido
#define MatriZ_H // defina

typedef struct matriz
{
    int linha;  // linha
    int coluna; // coluna
    int *vet;
} Matriz;

Matriz *criaMatriz(int m, int n);

void insereElemMatriz(Matriz *mat);

Matriz *multMatriz(Matriz *mat_a, Matriz *mat_b);
Matriz *calculaTransposta(Matriz *matriz);

void destroiMatriz(Matriz *matrix);

#endif // fim