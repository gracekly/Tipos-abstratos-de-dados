//grace kelly barros araujo dos santos
#include "lde.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------------------------------------------------------------------
DLList *dllCreate() {
  DLList *l;
  l = (DLList *)malloc(sizeof(DLList));
  if (l != NULL) {
    l->first = NULL;
    l->cur = NULL;
    return l;
  }
  return NULL;
}
//----------------------------------------------------------------------

int dllInsertAsFirst(DLList *l, void *data) {
  DLNode *newnode;
  if (l != NULL) {
    newnode = (DLNode *)malloc(sizeof(DLNode));
    if (newnode != NULL) {
      newnode->data = data;
      newnode->next = l->first;
      newnode->prev = NULL;

      if (l->first != NULL) {
        l->first->prev = newnode;
      }
      l->first = newnode;
      return TRUE;
    }
  }
  return FALSE;
}
//----------------------------------------------------------------------
int dllInsertAsLast(DLList *l, void *data) {
  DLNode *newnode, *last = NULL;
  if (l != NULL) {
    newnode = (DLNode *)malloc(sizeof(DLNode));
    if (newnode != NULL) {
      newnode->data = data;
      newnode->next = NULL;
      if (l->first != NULL) {
        last = l->first;
        while (last->next != NULL) {
          last = last->next;
        }
      }
      newnode->prev = last;
      if (last != NULL) {
        last->next = newnode;
      } else {
        l->first = newnode;
      }
      return TRUE;
    }
  }
  return FALSE;
}

//----------------------------------------------------------------------

void **listarElementos(DLList *l) {
  if (l != NULL) {
    int cont;
    cont = contarElementos(l);
    void **elementos = (void **)malloc(sizeof(void *) * cont);
    if (elementos != NULL) {
      if (l->first != NULL) {
        DLNode *aux = l->first;
        int i = 0;
        while (aux != NULL) {
          elementos[i] = aux->data;
          aux = aux->next;
          i++;
        }
        return elementos;
      }
    }
  }
  return NULL;
}

//----------------------------------------------------------------------
void *dllQuery(DLList *l, void *nome, void *idade, void *nota,
               int (*cmp)(void *, void *, void *, void *)) {
  DLNode *spec;
  int stat = FALSE;
  if (l != NULL) {
    if (l->first != NULL) {
      spec = l->first;
      stat = cmp(spec->data, nome, idade, nota);
      while (stat != TRUE && spec->next != NULL) {
        spec = spec->next;
        stat = cmp(spec->data, nome, idade, nota);
      }
      if (stat == TRUE) {
        return spec->data;
      }
    }
  }
  return NULL;
}
//----------------------------------------------------------------------
void *dllRemoveSpec(DLList *l, void *nome, void *idade, void *nota,
                    int (*cmp)(void *, void *, void *, void *)) {
  DLNode *nextnode, *prevnode, *spec;
  void *data;
  int stat = FALSE;

  if (l != NULL) {
    if (l->first !=NULL) {
      spec = l->first;
        stat = cmp(spec->data, nome, idade, nota);
        while ( stat != TRUE && spec->next != NULL ) {
          spec = spec->next;
          stat = cmp(spec->data, nome, idade, nota);
        }
        if (stat == TRUE) {
          data = spec->data;
          nextnode = spec->next;
          prevnode = spec->prev;
          if (prevnode != NULL) {
            prevnode->next = nextnode;
          } else {
            l->first = nextnode;
          }
          if (nextnode != NULL) {
            nextnode->prev = prevnode;
          }
          free(spec);
          return data;
        }
      }
    }
    
  return NULL;
}
//---------------------------------------------------------------------
int dllDestroy(DLList *l) {
  if (l != NULL) {
    if (l->first == NULL) {
      free(l);
      return TRUE;
    }
  }
  return FALSE;
}
//---------------------------------------------------------------------
int esvaziarLista(DLList *l) {
  int nElementos = 0;
  if (l != NULL) {

    if (l->first != NULL) {
      DLNode *current = l->first;
      DLNode *next;

      while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
      }
    
      l->first = NULL;
      nElementos = contarElementos(l);
      
    }
  }
  return nElementos;
}

//----------------------------------------------------------------------
int contarElementos(DLList *l) {
  DLNode *aux;
  int n = 0;
  if (l != NULL) {
    if (l->first != NULL) {
      aux = l->first;

      while (aux != NULL) {
        n++;
        aux = aux->next;
      }
    }
  }
  return n;
}
