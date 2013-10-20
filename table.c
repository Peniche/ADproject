#ifndef _TABLE_H
#define _TABLE_H

#include "list-private.h"

struct table_t;   /* A definir pelo grupo em table-private.h */

/* Função para criar/inicializar uma nova tabela hash, com n  
 * linhas(n = módulo da função hash)
 */
 int hash(int n_lists, char *key) {
  
  if(n_lists == 0 || key == NULL) // se o numero de listas for zero ou nao houver chaves retorna -1,
    return -1;                    //senao retorna o comprimento da chave a dividir pelo numero de listas
  
  return strlen(key) % n_lists;
}
struct table_t *table_create(int n){//table == varias listas

	struct table_t *new = (struct table_t*) malloc(sizeof(struct table_t));~//reserva o espaço memoria
	
  int count;//variavel

  if(new != NULL){
  	new->n_lists = n;
  	new->lists = (struct list_t**) calloc(n, sizeof(struct list_t*));//reserva e inicia logo a variavel a zero

  	for(count = 0; count < new->n_lists; count++)
    	new->lists[count] = list_create();

  	return new;}
  	
  return NULL;
}
 struct table_t *table_t = (struct table_t *) malloc(sizeof(struct table_t));
 
  if(l == NULL){
        printf("ERROR: Out of memory\n");//erros de reserva da memoria
        return NULL;
    }
    //falta criar o n_lists e o novo
}
void table_destroy(struct table_t *table);

 int count;

  if(table != NULL) {

    for(count = 0; count < table->n_lists; count++)
      if(table->lists[count] != NULL)   
        list_destroy(table->lists[count]);

    free(table->lists);
    free(table);  
  }

		
		/* Funcao para adicionar um elemento na tabela.
 * A função vai copiar a key (string) e os dados num 
 * espaco de memoria alocado por malloc().
 * Se a key ja existe, vai substituir essa entrada 
 * pelos novos dados.
 * Devolve 0 (ok) ou -1 (out of memory)
 */
int table_put(struct table_t *table, char *key, struct data_t *data){
	  
if( table == NULL || key == NULL || data == NULL )
    return -1;

  struct data_t *nova = table_get(table, key);
  int indice = hash(table->n_lists, key);

  if(indice == -1)
    return -1;

  if(nova == NULL)
    list_add(table->lists[indice], entry_create(strdup(key), data_dup(data)));
  else {
    data_destroy(nova);
    struct entry_t *entry = list_get(table->lists[indice], key);
    data_destroy(entry->value);
    entry->value = data_dup(data);
  }

  return 0;
}

/* Funcao para adicionar um elemento na tabela caso a chave
 * associada ao elemento nao exista na tabela. Caso a chave
 * exista, retorna erro.
 * A função vai copiar a key (string) e os dados num 
 * espaco de memoria alocado por malloc().
* Devolve 0 (ok) ou -1 (chave existe ou out of memory)
 */
int table_conditional_put(struct table_t *table, char *key, struct data_t *data);

/* Funcao para obter um elemento da tabela.
 * O argumento key indica a chave da entrada da tabela. 
 * A função aloca memoria para armazenar uma *COPIA* 
 * dos dados da tabela e retorna este endereco. 
 * O programa a usar essa funcao deve
 * desalocar (utilizando free()) esta memoria.
 * Em caso de erro, devolve NULL
 */
struct data_t *table_get(struct table_t *table, char *key);

/* Funcao para remover um elemento da tabela. Vai desalocar
 * toda a memoria alocada na respetiva operação table_put().
 * Devolve: 0 (ok), -1 (key not found)
 */
int table_del(struct table_t *table, char *key);


/* Devolve o numero de elementos da tabela.
 */
int table_size(struct table_t *table);

/* Devolve um array de char * com a copia de todas as 
 * keys da tabela, e um ultimo elemento a NULL.
 */
char **table_get_keys(struct table_t *table);

if((keys[numMallocs] = strdup(tempNode->entry->key))) {
                    numMallocs ++;
                    tempNode = tempNode->prox;
                }
/* Desaloca a memoria alocada por table_get_keys()
 */
void table_free_keys(char **keys);
 
 int i;
	for(i=0; keys[i] != NULL; i++){
		free(keys[i]);
		keys[i] = NULL;
	}

	free(keys);



#endif
