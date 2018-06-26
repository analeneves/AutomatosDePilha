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

Pilha* cria (void);
No* ins_ini (No* l, int v);
No* ret_ini (No* l);
void push (Pilha* p, int v);
int pop(Pilha* p);
int vazia (Pilha* p);
void libera (Pilha* p);
void imprimePilha(Pilha* p);
int RECONHECE_PAR(Pilha* p);
void inicio ();
 #endif
