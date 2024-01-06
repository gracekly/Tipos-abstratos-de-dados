// grace kelly barros araujo dos santos

#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------------------
int abpCreate(TNode *raiz) {

  raiz = NULL;

  if (raiz == NULL) {

    return TRUE;
  }
  return FALSE;
}

//-----------------------------------------------------------

TNode *abpInsert(TNode *t, void *data, int (*cmp)(void *, void *)) {
  if (t != NULL) {

    int stat = cmp(data, t->data);

    if (stat <= 0) {
      t->left = abpInsert(t->left, data, cmp);
    } else {
      t->right = abpInsert(t->right, data, cmp);
    }

    return t;

  } else {
    TNode *newnode = (TNode *)malloc(sizeof(TNode));

    if (newnode != NULL) {
      newnode->data = data;
      newnode->left = NULL;
      newnode->right = NULL;

      return newnode;

    } else {
      return NULL;
    }
  }
}

//----------------------------------------------------------------

TNode *abpRemove(TNode *t, void *key, int (*cmp)(void *, void *), void **data) {
  void *data2;
  int stat;
  TNode *aux;

  if (t != NULL) {
    stat = cmp(key, t->data);

    if (stat < 0) {
      t->left = abpRemove(t->left, key, cmp, data);
      return t;
      
    } else if (stat > 0) {
      t->right = abpRemove(t->right, key, cmp, data);
      return t;
      
    } else {

      if (t->left == NULL && t->right == NULL) { // se for um nó folha
        *data = t->data;
        free(t);
        return NULL;
        
      } else if (t->left == NULL) { // se tiver só filho na direita
        aux = t->right;
        *data = t->data;
        return aux;
        
      } else if (t->right == NULL) { // tem só filho na esquerda
        aux = t->left;
        *data = t->data;
        return aux;

      } else {
        *data = t->data;
        t->left = abpRemoveMaior(t->left, cmp, &data2);
        t->data = data2;
        return t;
      }
    }
  }
  *data = NULL;
  return NULL;
}

//----------------------------------------------------------------------

TNode *abpRemoveMaior(TNode *t, int (*cmp)(void *, void *), void **data) {
  TNode *aux;

  if (t != NULL) {
    if (t->right != NULL) {
      t->right = abpRemoveMaior(t->right, cmp, data);
      
    } else {
      if (t->left != NULL) {
        aux = t->left;
        *data = t->data;
        free(t);
        return aux;
        
      } else {
        *data = t->data;
        free(t);
        return NULL;
      }
    }
  }
  *data = NULL;
  return NULL;
}

//----------------------------------------------------------------

void *abpQuery(TNode *t, void *key, int (*cmp)(void *, void *)) {
  int stat;
  if (t != NULL) {
    stat = cmp(key, t->data);
    
    if (stat == 0) {
      return t->data;
      
    } else if (stat < 0) {
      return abpQuery(t->left, key, cmp);
      
    } else {
      return abpQuery(t->right, key, cmp);
    }
  }
  return NULL;
}

// --------------------------------------------------------------------

void simetrico(TNode *t, void (*visit)(void *)) {
  if (t != NULL) {
    simetrico(t->left, visit);
    visit(t->data);
    simetrico(t->right, visit);
  }
}

//----------------------------------------------------------------------

int abpEsvaziar(TNode **raiz) {

  if (*raiz != NULL) {
    // Primeiro, esvazie a subárvore esquerda
    abpEsvaziar(&((*raiz)->left));

    // Em seguida, esvazie a subárvore direita
    abpEsvaziar(&((*raiz)->right));

    // Agora, libere a memória do nó atual
    free(*raiz);

    // Finalmente, defina o ponteiro para NULL
    *raiz = NULL;

    return TRUE;
  }
  return FALSE;
}

//---------------------------------------------------------------------

int abpDestroy(TNode *t) {
  if (t == NULL) {

    free(t);
    return TRUE;
  }
  return FALSE;
}

//--------------------------------------------------------------------

int ehVazia(TNode *raiz) {
  if (raiz == NULL ||
      (raiz->data == NULL && raiz->left == NULL && raiz->right == NULL)) {
    return TRUE;
  }
  return FALSE;
}
