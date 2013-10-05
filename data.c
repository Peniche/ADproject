#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct data_t *data_create (int size) {
	struct data_t d = (struct data_t) malloc(sizeof(struct data_t));/*primeiro malloc para reservar memoria*/
 
	 if (d == NULL) {
	  printf("Memoria insuficiente\n");/*verifica os erros de memoria reservada*/
		return NULL;
	  }

	d->datasize = size;
	d->data = malloc(d->datasize);/*segundo malloc para*/

	if (d->data == NULL) {
		printf("Memoria insuficiente\n");
		return NULL;
	}

	return d;
}

struct data_t *data_create2 (int size, void *data) {

	struct data_t d = (struct data_t) malloc(sizeof(struct data_t));
 
	if ( d != NULL && *data != NULL ) {
		d->data = *data;
		d->datasize = size;
		return d;
	}
	return NULL;
}

void data_destroy (struct data_t *data) {

	free(data);
	free(d);

}

struct data_t *data_dup (struct data_t *data) {

	struct data_t dc = (struct data_t) malloc(sizeof(struct data_t));
 
	if(dc->data == NULL) {
		printf("Memoria insuficiente\n");
		return NULL;
        }
		memcpy (dc->data, d->data, sizeof (struct data_t);
		dc->datasize = d->datasize;
		return dc;
	}
	return NULL;
}
