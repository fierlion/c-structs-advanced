#include <glib.h>
#include <string.h>
#include "dlist.c"

// note glib-2.0 is difficult to link in OSX
int *create_int(int data) {
  int *value = malloc(sizeof(data));
  memset(value, 0, sizeof(data));
  *value = data;
  return(value);
}

void destroy_int(void *data) {
  free((int *)data);
}

typedef struct {
  DList *dd;
} dfixture;

void dlist_setup(dfixture *df, gconstpointer test_data) {
  df->dd = malloc(sizeof(DList));
  dlist_init(df->dd, &destroy_int);
}

void dlist_teardown(dfixture *df, gconstpointer test_data) {
  dlist_destroy(df->dd);
}
