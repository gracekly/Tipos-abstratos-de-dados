// grace kelly barros araujo do santos

#ifndef TAD_TREE_H
#define TAD_TREE_H

#define FALSE 1
#define TRUE 0




typedef struct _tnode_ {
    void *data;
    struct _tnode_ *left;
    struct _tnode_ *right;
} TNode;

typedef struct _aluno_ {
    int matricula;
} Aluno;



int abpCreate(TNode *raiz); //----

TNode *abpInsert(TNode *t, void *data, int (*cmp)(void *, void *)); //----

TNode *abpRemove(TNode *t, void *key, int (*cmp)(void *, void *), void **data);//-------------

TNode *abpRemoveMaior(TNode *t, int (*cmp)(void *, void *), void **data); //------------

void *abpQuery(TNode *t, void *key, int (*cmp)(void *, void *)); // -------

void simetrico(TNode *t, void (*visit)(void *)); //---------------

void visit(void *data);

int abpContarElm(TNode *t);

int abpEsvaziar(TNode **raiz); //----------------

int abpDestroy(TNode *t); //

int ehVazia(TNode *raiz);


#endif