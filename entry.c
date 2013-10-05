#include <stdio.h>
#include <stdlib.h>
#include "entry.h"
#include "data.h"

struct entry_t *entry_create(char *key, struct data_t *data){

	struct entry_t *e = (struct entry_t) malloc(sizeof(struct entry_t));

	if ( e != NULL ) {
		e->key = key;
		e->timestamp = 0;
		e->value = data;
		return d;
	}
	return NULL;
}

void entry_destroy(struct entry_t *entry){

	while ( entry != NULL ) {
    		free(entry->key);
    		free(entry->value);
  	}
 	free(entry);
}

struct entry_t *entry_dup(struct entry_t *entry){

	struct entry_t *dup = (struct entry_t*) malloc( sizeof(struct entry_t));
 
    while(dup != NULL){
    	
    	memcpy(dup->key, key, strlen(key));
    	strcpy (dup,entry);
    	dup->value = data_dup(data);
  
    	return c;	
	}

	return NULL;
}
