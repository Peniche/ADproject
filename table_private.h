#ifndef _TABLE_PRIVATE_H
#define _TABLE_PRIVATE_H

#include "table.h"

struct table_t {
  int n_lists;
  struct list_t **lists;
};

int hash(int n_lists, char *key);

void table_print(struct table_t *table);

#endif
