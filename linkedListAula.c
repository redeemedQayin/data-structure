#include <stdio.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;
} REGISTRO;

typedef struct x{
	REGISTRO reg;
	struct x* prox;
} ELEMENTO;

typedef struct{
	ELEMENTO *inicio;
} LINKEDLIST;

//funções de operação da lista:

void initList(LINKEDLIST *l){
	l->inicio = NULL;
}

int countList(LINKEDLIST *l){
	int n =0;
	ELEMENTO *aux = l->inicio;
	while(aux != NULL){
		n++;
		aux = aux->prox;
	}
	return n;
}

void printList(LINKEDLIST *l){
	printf("\n\n-------- Linked List ---------\n\n");

	ELEMENTO *aux = l->inicio;
	while(aux != NULL){
		printf("[%d] ", aux->reg.chave);
		aux = aux->prox;
	}

	printf("\n--------------END-------------\n\n");

}

ELEMENTO *searchList(LINKEDLIST *l, TIPOCHAVE k){
	ELEMENTO *aux = l->inicio;
	while(aux != NULL && aux->reg.chave < k) 
		aux = aux->prox;
	if(aux != NULL && aux->reg.chave == k)
		return aux;

	return NULL;
}

int main(int argc, char const *argv[]){

	/* code */
	return 0;
}



