#include <stdlib.h>
#include "queue.h"

Queue* Q_createNew(void) {
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	queue->list = Ll_createNewEmpty();
	return queue;
}

void Q_enqueue(Queue* queue, void* element) {
	Ll_addLast(queue->list, element);
}

void* Q_dequeue(Queue* queue) {
	return Ll_removeFirst(queue->list);
}

int Q_isEmpty(Queue* queue) {
	return Ll_isEmpty(queue->list);
}

void Q_clear(Queue* queue) {
	Ll_clear(queue->list);
}