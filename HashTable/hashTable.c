#include <stdio.h>
#include <stdlib.h>

#define TAM 31

typedef struct No{
	int chave;
	struct No *proximo;
}No;

typedef struct{
	No *inicio;
	int tam;
}Lista;

void inicializarLista(Lista *l){
	l->inicio = NULL;
	l->tam = 0;
}

void inserirNaLista(Lista *l, int valor){
	No *n = malloc(sizeof(No));
	if (n)
	{
		n->chave = valor;
		n->proximo = l->inicio;
		l->inicio = n;
		l->tam++;
	}
	else
	{
		printf("\nErro ao alocar memoria\n");
	}
}

int buscarNaLista(Lista *l, int chaveBuscada){
	No *aux = l->inicio;
	while(aux && aux->chave != chaveBuscada){
		aux = aux->proximo;
	}
	if(aux){
		return aux->chave;
	}
	return 0;
}

void imprimirLista(Lista *l){
	No *aux = l->inicio;
	printf("Tam: %d: ", l->tam);
	while (aux){
		printf("%d ", aux->chave);
		aux = aux->proximo;
	}
}

void inicializarTabela(Lista t[]) {
	for(int i = 0; i < TAM; i++){
		inicializarLista(&t[i]);
	}
}

int funcaoHash(int chave) {
	return chave % TAM;
}

void inserir(Lista t[], int valor){
	int id = funcaoHash(valor);
	inserirNaLista(&t[id], valor);
}

int busca(Lista t[], int chave){
	int id = funcaoHash(chave);
	return buscarNaLista(&t[id], chave);
}

void imprimir(Lista t[]){
	for(int i = 0; i < TAM; i++){
		printf("%2d: ", i);
		imprimirLista(&t[i]);
		printf("\n");
	}
}

int main() {
	int opcao, valor, retorno;
	Lista tabela[TAM];
	inicializarTabela(tabela);
	
	do{
		printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				printf("\tQual valor deseja inserir? ");
				scanf("%d", &valor);
				inserir(tabela, valor);
				break;
			case 2:
				printf("\tQual valor deseja buscar? ");
				scanf("%d", &valor);
				retorno = busca(tabela, valor);
				if(retorno != 0){
					printf("\tValor encontrado: %d\n", retorno);
				}
				else{
					printf("\tValor não encontrado!\n");
				}
				break;
			case 3:
				imprimir(tabela);
				break;
			default:
				printf("Opcao invalida!\n");
		}

	}while(opcao != 0);


	return 0;
}
