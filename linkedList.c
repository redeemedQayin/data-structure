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

ELEMENTO *searchList(LINKEDLIST *l, TIPOCHAVE k, ELEMENTO **ant){
	ELEMENTO *aux = l->inicio;
	*ant = NULL;
	while(aux != NULL && aux->reg.chave < k){
		*ant = aux;
		aux = aux->prox;
	}
	if(aux != NULL && aux->reg.chave == k)
		return aux;

	return NULL;
}

int insertL(LINKEDLIST *l, REGISTRO newR){
	ELEMENTO *aux, *ant;
	TIPOCHAVE key = newR.chave;

	aux = searchList(l, key, &ant);

	if(aux != NULL)
		return 1;
	
	aux = (ELEMENTO*)malloc (sizeof(ELEMENTO));
	aux->reg = newR;
	if(ant == NULL){
		aux->prox = l->inicio;
		l->inicio = aux;
	} else {
		aux->prox = ant->prox;
		ant->prox = aux;
	}
	return 0;
}

int removeL(LINKEDLIST *l, TIPOCHAVE k){
	ELEMENTO *aux, *ant;
	aux = searchList(l, k, &ant);
	if(aux == NULL)
		return 1;

	if(ant == NULL)
		l->inicio = aux->prox;
	else
		ant->prox = aux->prox;
	free(aux);
	return 0;
}

int freeL(LINKEDLIST *l){
	ELEMENTO *aux = l->inicio, *delet;

	while(aux != NULL){
		delet = aux;
		aux = aux->prox;
		free(delet);
	}
	l->inicio = NULL;
}

int main(int argc, char const *argv[]){

	int op, r;
	LINKEDLIST l;
	initList(&l);

	do{
		system("clear");
		printf("---------- Linked List -----------\n");
		printf("1-Imprimir a lista\n2-Inserir um novo elemento\n");
		printf("3-Excluir um elemento\n0-Sair\n");			
		scanf("%d", &op);

		switch(op){
			case 1:
				printList(&l);
			break;

			case 2:
				printf("Digite a chave que deseja inserir\n");
				REGISTRO newR;
				scanf("%d", &newR.chave);
				r = insertL(&l, newR);
				if(r)
					printf("[\nERROR::ELEMENT_ARLEADY_EXIST]\n");
				else
					printf("\n[SUCESS!]\n");	
			break;

			case 3:
				printf("Digite a chave do elemento a excluir:\n");
				TIPOCHAVE k;
				scanf("%d", &k);
				r = removeL(&l, k);
				if(r)
					printf("\nERROR::404::ELEMENT_NOT_EXIST\n");
				else
					printf("\n[SUCESS]\n");
			break;

			case 0:
				printf("Volte sempre\n");
			break;
			
			default:
				printf("\nERROR::INVALID_OPTION::\n");
		}

		getchar();
		getchar();
	} while(op != 0);
	freeL(&l);

	return 0;
}



