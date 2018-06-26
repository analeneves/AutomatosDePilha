 #include <stdio.h>
 #include <stdlib.h>
 #include "aut_pilha.h"
  //Este autômato de pilha reconhece linguagens do tipo {0^n1^n/n>0}
   Pilha *pil;
   //Função para criar a pilha
   Pilha* cria (void) {
     Pilha* p = (Pilha*) malloc(sizeof(Pilha));
     p->prim = NULL;
     return p;
   }

   //Função auxiliar para inserir no início
   No* ins_ini (No* l, int v) {
     No* p = (No*) malloc(sizeof(No));
     p->info = v;
     p->prox = l;
     return p;
   }

   //Função auxiliar para retirar do início
   No* ret_ini (No* l){
     No* p = l-> prox;
     free(l);
     return(p);
   }

   //Inserção na PILHA: int v é o dado do Nó
   void push (Pilha* p, int v){
     p-> prim = ins_ini(p-> prim, v);
   }

   //Função de remoção da pilha
   void pop(Pilha* p){
     int v;
     if(vazia(p)){
       printf("Pilha vazia!\n");
       exit(1); //se a pilha está vazia, sai do programa
     }
     v = p->prim->info;
     p->prim= ret_ini(p->prim);
     return v;
   }

   //Função auxiliar para verificar se a pilha está vazia
   int vazia (Pilha* p){
     return (p-> prim==NULL);
   }

   void libera (Pilha* p){
     No* r = p-> prim;
     while (r!=NULL) {
       No* t=r->prox;
       free(r);
       r=t;
     }
     free(p);
   }

   //Função que exibe todos elementos da pilha
   void imprimePilha(Pilha* p){
     No* r= p->prim;
     printf("Pilha:\n");
     if (r== NULL)
       printf("A pilha está vazia!");
       while (r!=NULL) {
        printf(".: |%d| :.\n", r->info);
        r=r->prox;
       }
   }

   int RECONHECE_PAR(void){
     int q=0, teste=0;
     printf("Cadeia a ser processada:\n");
     for (i = 0; i < n; i++)
     printf("%d", cadeia[i]);
     printf("\nElemento do topo da pilha:\n%d\nEstado do autômato: %d\n\n", dado);
        for(i=0; i<n; i++){
          if (q == -1)
          break;
          printf("Processando %d elemento da cadeia: %d\n", i+1, cadeia[i]);
          if (cadeia[i] == 0 && pil->prim->info == 0 && q==0) {
            dado=pop(pil);
            push(pil,0);
            push(pil,1);
            imprimePilha(pil);
            printf("Estado do autômato: %d\n\n", q);
          } else
          if (cadeia[i] == 0 && pil->prim->info == 1 && q==0) {
            dado = pop(pil);
            push(pil,1);
            push(pil,1);
            imprimePilha(pil);
            printf("Estado do autômato: %d\n\n", q);
          } else
          if (cadeia[i] == 1 && pil->prim->info == 1 && q==0) {
            q=1;
            dado = pop(pil);
            imprimePilha(pil);
            printf("Estado do autômato: %d\n\n", q);
          } else
          if (cadeia[i] == 1 && pil->prim->info == 1 && q==1) {
            dado = pop(pil);
            imprimePilha(pil);
            printf("Estado do autômato: %d\n\n", q);
          } else {
            q=-1;
            imprimePilha(pil);
            printf("Estado final!\n");
            printf("Estado do autômato: %d\n\n", q);
          }
        }

   printf("Fim do reconhecimento da cadeia!\n");
   if (q == -1)
     return teste;
     else {
     printf("\nProcessando pilha\n");
     while (pil->prim!=NULL) {
       if (q == 0 && pil->prim->info == 0) {
         q=2;
         dado = pop(pil);
         imprimePilha(pil);
         printf("Estado do autômato: %d\n\n", q);
       } else
       if (q == 1 && pil-> prim->info ==0) {
         q=2;
         dado=pop(pil);
         imprimePilha(pil);
         printf("Estado do autômato: %d\n\n", q);
       } else{
         q=-1;
         dado=pop(pil);
         imprimePilha(pil);
         printf("Estado final!\n");
         printf("Estado do autômato: %d\n\n", q);
       }
     }
     printf("Fim do processamento da pilha!\n");
     if (q==2 && pil->prim == NULL)
      teste = 1;
      return teste;
   }
 }

   void inicio (){
     printf("Insira o tamanho da sequência\n");
     scanf("%d",&n);
     system("clear");
     cadeia = (int*)malloc(n*sizeof(int));

     printf("Insira a sequência:\n");
     for (i = 0; i < n; i++) {
      scanf("%d",&cadeia[i]);
     }
     system("clear");
     printf("Insira o primeiro elemento da lista:\n");
     scanf("%d\n",&dado);
     system("clear");
   }
