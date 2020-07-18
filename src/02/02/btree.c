#include "btree.h"
#include "queue.h"

BTree *btree_init(int data) {
  BTree *tree = malloc(sizeof(BTree));
  tree->left = NULL;
  tree->right = NULL;
  tree->data = data;
  return tree;
}

bool btree_is_bst(BTree *tree) {
  if (!tree) {
    return false;
  }

  Queue *queue = queue_init();
  queue_enq(queue, tree->left);
  queue_enq(queue, tree);
  queue_enq(queue, tree->right);

  // in order traversal
  // fill queue
  // iterate through queue and
  // check if last is less than next
  while (queue_size(queue) > 0) {
    BTree *item = queue_deq(queue);
    if (!item)
      continue;

    queue_enq(queue, item->left);
    queue_enq(queue, item);
    queue_enq(queue, item->right);
  }

  return false;
}
