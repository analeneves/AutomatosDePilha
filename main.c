#include <stdio.h>
#include <stdlib.h>
#include "aut_pilha.h"
Pilha *pil;

int main() {
	int valor;
	inicio();
	pil = cria();
	push(pil, dado);
	valor = RECONHECE_PAR(pil);

	if (valor = 1)
		printf("Cadeia reconhecida!\n\n");
	else
		printf("Cadeia NÃO reconhecida!\n\n");

	return 0;
}
