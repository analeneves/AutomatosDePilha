target: main.c aut_pilha.c
	gcc main.c aut_pilha.c -o aut

clean: aut
	rm -rf aut