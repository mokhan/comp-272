typedef struct mnode {
  struct mnode *left;
  struct mnode *parent;
  struct mnode *right;
  int value;
} MeldableHeap;

MeldableHeap *meldable_heap_initialize(int value);
MeldableHeap *meldable_heap_add(MeldableHeap *heap, int value);
MeldableHeap *meldable_heap_merge(MeldableHeap *heap, MeldableHeap* other);
void meldable_heap_inspect(MeldableHeap *heap);
void meldable_heap_remove(MeldableHeap *heap);
