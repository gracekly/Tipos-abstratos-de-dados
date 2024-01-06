//
// Created by grace on 17/09/2023.
//
#include "cofo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------------------------------------------------------------------------
gCofo *criarCofo(int max_itens) {
  if (max_itens > 0) {
    gCofo *cofo = (gCofo *)malloc(sizeof(gCofo));

    if (cofo != NULL) {
      cofo->item = (void **)malloc(sizeof(void *) * max_itens);

      if (cofo->item != NULL) {
        cofo->num_itens = 0;
        cofo->max_itens = max_itens;
        cofo->current = -1;
        return cofo;
      }
      free(cofo->item);
    }
    free(cofo);
  }
  return NULL;
}
//--------------------------------------------------------------------------------------
int inserirNoCofo(gCofo *cofo, void *item) {

  if (cofo != NULL) {
    if (cofo->num_itens < cofo->max_itens) {
      cofo->item[cofo->num_itens] = item;
      cofo->num_itens++;
      return TRUE;
    }
  }

  return FALSE;
}
//---------------------------------------------------------------------------------------
void *removerDoCofo(gCofo *cofo, void* chave1, void* chave2, void* chave3, int (*cmp)(void*, void*, void*, void*))
 {
  if (cofo != NULL && cofo->num_itens > 0) {
    void *encontrado = NULL;
    for (int i = 0; i < cofo->num_itens; i++) {
      if (cmp(cofo->item[i], chave1, chave2,chave3) == TRUE) {
        encontrado = cofo->item[i];
        for (int j = i; j < cofo->num_itens - 1; j++) {
          cofo->item[j] = cofo->item[j + 1];
        }
        cofo->num_itens--; // Mova esta linha para fora do loop for
        break;
      }
    }
    return encontrado;
  }
  return NULL;
}
//---------------------------------------------------------------------------------------
void* removerPorIndice(gCofo *cofo, int i) {
  if (cofo!=NULL) {
    if (cofo->num_itens>0){
      i -=1;
      
      if (i<= cofo->max_itens-1) {
        void* removido = NULL;
        removido = cofo->item[i];
        for (int j = i; j<cofo->num_itens;j++) {
          cofo->item[j] = cofo->item[j+1];
        }
        cofo->num_itens--;
        return removido;
      }
    }
    return NULL;
  }






  
}

//---------------------------------------------------------------------------------

void *consultarElemento(gCofo *cofo, void* nome, void* idade, void* nota, int (*cmp) (void*, void*, void*, void*)) {
  if (cofo != NULL) {
    if (cofo->num_itens > 0) {
     

      for (int i = 0; i < cofo->num_itens; i++) {
        if (cmp(cofo->item[i], nome, idade, nota) == TRUE) {
             void *procurado = cofo->item[i];
            return procurado;
        }
        
       
         
          }
        }
      }
    
  
  return NULL;
}
//-------------------------------------------------------------------------------------

void **listarElementos(gCofo *cofo) {
  if (cofo != NULL) {
    if (cofo->num_itens > 0) {
      void **elementos = (void **)malloc(sizeof(void *) * cofo->num_itens);
      if (elementos != NULL) {
        for (int i = 0; i < cofo->num_itens; i++) {
          cofo->current = i;
          elementos[i] = cofo->item[cofo->current];
        }
        return elementos;
      }
    }
  }

  return NULL;
}
//-----------------------------------------------------------------------------------
int destruirCofo(gCofo *cofo) {
  if (cofo != NULL) {
    if (cofo->num_itens == 0) {
      free(cofo->item);
      free(cofo);
      return TRUE;
    }
  }
  return FALSE;
}

//------------------------------------------------------------------------------------

int esvaziarCofo(gCofo *cofo) {
  if (cofo != NULL) {
    free(cofo->item);
    cofo->num_itens = 0;
    return cofo->num_itens;
  }
  return FALSE;
}

//------------------------------------------------------------------------------------
