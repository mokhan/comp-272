#include "node.h"

typedef void (*Printer)(void *);
typedef struct node List;

List *list_initialize(void *data);
List *list_get(List *from, int index);
List *list_add(List *head, void *data);
int list_size(List *list);
void list_inspect(List *self, Printer printer);
