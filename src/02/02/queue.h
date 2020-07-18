typedef struct sll_node {
  struct sll_node *next;
  void *data;
} Queue;

Queue *queue_init();
int queue_size(Queue *queue);
void *queue_deq(Queue *queue);
void queue_enq(Queue *queue, void* data);
