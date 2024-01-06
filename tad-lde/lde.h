//Grace Kelly Barros Araujo dos Santos

#ifndef TAD_LDE_H
#define TAD_LDE_H

#define FALSE 1
#define TRUE 0



typedef struct _dlnode_{
  void* data;
  struct _dlnode_ *prev;
  struct _dlnode_ *next;
}DLNode;

typedef struct _dllist_ {
  DLNode *first, *cur;
} DLList;



DLList *dllCreate(); //x

int dllInsertAsFirst(DLList *l, void* data);//x

int dllInsertAsLast(DLList *L, void* data);//x

void **listarElementos(DLList *l);

void *dllQuery(DLList *l, void* nome, void* idade, void* nota, int (*cmp) (void*, void*, void*, void*));//x

void *dllRemoveSpec(DLList* l, void* nome, void* idade, void* nota, int (*cmp) (void*, void*, void*, void*));//x

int esvaziarLista(DLList *l);

int dllDestroy(DLList *l);//x

int contarElementos(DLList *l);





#endif