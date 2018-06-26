#ifndef AUT_PILHA_H
#define AUT_PILHA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int i, n, dado, *cadeia;

struct no {
   int info;
   struct no* prox;
 };
 typedef struct no No;

struct pilha {
   No* prim;
 };
 typedef struct pilha Pilha;

 #endif
