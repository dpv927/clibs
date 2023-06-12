#pragma once
#include "../linked_list/linkedList.h"

typedef struct Queue Queue;

struct Queue {
	LinkedList* list;
};

/**
 * @brief Creates a new empty queue.
 *
 * @return Pointer to the new empty queue. **/
Queue* Q_createNew(void);

/**
 * @brief Adds an element to the end of the queue.
 *
 * @param queue Pointer to the queue.
 * @param value Pointer to the element to be added. **/
void Q_enqueue(Queue* queue, void* element);

/**
 * @brief Removes and returns the first element from the queue.
 *
 * @param list Pointer to the linked list.
 * @return Pointer to the removed element. **/
void* Q_dequeue(Queue* queue);

/**
 * @brief Checks if the queue is empty.
 *
 * @param list Pointer to the queue.
 * @return 1 if the queue is empty, 0 otherwise. **/
int Q_isEmpty(Queue* queue);

/**
 * @brief Clears the queue, removing all elements.
 *
 * @param list Pointer to the queue. **/
void Q_clear(Queue* queue);