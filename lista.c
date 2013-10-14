#include "entry.h"
#include "data.h"
#include "list.h"
#include "list-private.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//private

static void node_destruir(Node n){

	entry_destroy(n->entry);
	free(n);
}

static int lista_vazia(List l){

	return l->head == NULL;
}

static void lista_remover_cabeca(List l){

	Node n = l->head;
	l->head = l->head->prox;
	node_destruir(n);
}

//end_private

struct list_t *list_create(){

	struct list_t *l = (struct list_t*) malloc ( sizeof(struct list_t));
 
    if(l == NULL){
        printf("ERROR: Out of memory\n");
        return NULL;
    }

	l->head = NULL;
	l->tail = NULL;

	l->size = 0;

	return l;
}

int list_destroy(struct list_t *list){

	if ( list == NULL )
		printf("Error.");

	while(!lista_vazia(list))
		lista_remover_cabeca(list);

	free(list);
	
	if( list == NULL )
		return 0;
	else 
		return -1;
}

int list_add(struct list_t *list, struct entry_t *entry){	
	
	if(list == NULL || entry == NULL)
	return -1;
 
	struct node_t *novo_no = (struct node_t *) malloc(sizeof(struct node_t));
 
	if(novo_no == NULL)
        	return -1;
 
	novo_no->entry = entry;
	novo_no->prox = NULL; 
 	novo_no->prev = NULL;
	     	
	
	if(list->size == 0){
		list->head = novo_no;
		list->tail = novo_no;		
		list->size++; 		
		return 0;
	}
 	
	struct node_t *no = list->head;
	struct node_t *aux = no->prox; //list->head->prox
	
	if( list->size == 1) {
		if(strcmp(entry->key, no->entry->key) < 0 ){
 			list->head = novo_no;     
			list->tail = no;			
			novo_no->prox = no;
			no->prev = list->head;
			list->size++;
			return 0;
		}

		else {
			no->prev = novo_no;
			novo_no->prox = no;
			list->tail = novo_no;
			list->size++;
			return 0;
		}
	}			
	while(aux != NULL ){
		if(strcmp(entry->key, aux->entry->key) < 0){
			no->prox = novo_no;
			novo_no->prox = aux;
			novo_no->prev = no;
			aux->prev = novo_no;
			list->size++;
			return 0;
		}

		if(strcmp(entry->key, aux->entry->key ) == 0){
			printf("erro, entrys iguals nao vai substituir");
			return -1;		
		}
 
		no = aux;
		aux = aux->prox; 

	}

	
	list->tail = novo_no;
	novo_no->prev = no;
	novo_no->prox = NULL;
	aux = novo_no;	
	list->size++;
 
	return 0;
	
}

int list_remove(struct list_t *list, char *key){
   
    if(list == NULL || key == NULL)
        return -1;
     
    struct node_t *no = list->head;
    struct node_t *aux = no->prox;
 
    if(strcmp(key, no->entry->key) == 0 ){
        list->head = aux;
        entry_destroy(no->entry);
        free(no);
        list->size--;
        return 0;
    }
 
    while(aux != NULL){
        if(strcmp(key, aux->entry->key) == 0 ){
        no->prox = aux->prox;
        entry_destroy(aux->entry);
        free(aux);
        list->size--; 
        return 0;      
        }   
        no = aux;
        aux = aux->prox; 
    }

    return -1;
}
struct entry_t *list_get(struct list_t *list, char *key){
 
    if(list == NULL || key == NULL)
        return NULL;
     
    struct node_t *no = list->head;
 
    while(no != NULL) {
        if(strcmp(no->entry->key, key) == 0)
        return no->entry;
        no = no->prox;  
    }
 
    return NULL;
 
}

int list_size(struct list_t *list){

	if ( list == NULL )
		return -1;

	return list->size;
}


char **list_get_keys(struct list_t *list) {

    char **keys = NULL;
    struct node_t *tempNode;
    int numMallocs = 0, counter = 0;

    if(list) {
        tempNode = list->head;

        // Aloca memoria para guardar todas as chaves da tabela
        if((keys = (char**)malloc((list->size + 1)*sizeof(char*)))) {

            // Percorre a tabela
            while(tempNode) {

                // Aloca memÃ³ria para cada chave e duplica a mesma
                if((keys[numMallocs] = strdup(tempNode->entry->key))) {
                    numMallocs ++;
                    tempNode = tempNode->prox;
                }
                else {
                    // Deu erro, temos que libertar tudo o que ja foi allocado !
                    printf("Malloc");
                    tempNode = NULL;
                    for(counter = 0; counter < numMallocs; counter ++) {
                        free(keys[counter]);
                    }
                    free(keys);
                    keys = NULL;
                    numMallocs = 0;
                }
            }

            // Confirma a cÃ³pia de todas as chaves e termina o vector com NULL
            if(keys && numMallocs == list->size) {
                keys[numMallocs] = NULL;
            }
        }
        else {
            printf("Malloc keys");
            keys = NULL;
        }
    }
    else {
        printf("NULL Lista");
    }
    return keys;

}


void list_free_keys(char **keys){

	int i;
	for(i=0; keys[i] != NULL; i++){
		free(keys[i]);
		keys[i] = NULL;
	}

	free(keys);
}

void print_list(struct list_t *list) {
  		struct node_t *pointer = list->head;
  		int i;

  		for(i = 0; pointer!= NULL; i++){
    		printf("%s\n", pointer->entry->key);
    		pointer = pointer->prox;
 		 }	
}
