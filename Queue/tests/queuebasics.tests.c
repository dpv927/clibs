#include <stdio.h>
#include <stdlib.h>
#include "queuebasics.tests.h"

void test_Q_enqueue_and_Q_dequeue() {
    Queue* queue = Q_createNew();

    int x = 10;
    int y = 20;

    Q_enqueue(queue, &x);
    Q_enqueue(queue, &y);

    int* firstValue = (int*)Q_dequeue(queue);
    int* secondValue = (int*)Q_dequeue(queue);

    if (firstValue != NULL && secondValue != NULL && *firstValue == x && *secondValue == y && Q_isEmpty(queue)) {
        printf("Successful test: Q_enqueue() and Q_dequeue() added and removed elements from the queue correctly.\n");
    } else {
        printf("Failed test: Q_enqueue() and Q_dequeue() did not add and remove elements from the queue correctly.\n");
        Q_clear(queue);
        free(queue);
        exit(-1);
    }
}

void test_Q_isEmpty() {
    Queue* queue = Q_createNew();

    if (Q_isEmpty(queue)) {
        printf("Successful test: Q_isEmpty() returned true for an empty queue.\n");
    } else {
        printf("Failed test: Q_isEmpty() did not return true for an empty queue.\n");
        Q_clear(queue);
        free(queue);
        exit(-1);
    }

    int x = 10;
    Q_enqueue(queue, &x);

    if (!Q_isEmpty(queue)) {
        printf("Successful test: Q_isEmpty() returned false for a non-empty queue.\n");
    } else {
        printf("Failed test: Q_isEmpty() did not return false for a non-empty queue.\n");
        Q_clear(queue);
        free(queue);
        exit(-1);
    }
}

void test_Q_clear() {
    Queue* queue = Q_createNew();

    int x = 10;
    int y = 20;

    Q_enqueue(queue, &x);
    Q_enqueue(queue, &y);

    Q_clear(queue);

    if (Q_isEmpty(queue)) {
        printf("Successful test: Q_clear() cleared the queue correctly.\n");
    } else {
        printf("Failed test: Q_clear() did not clear the queue correctly.\n");
        Q_clear(queue);
        free(queue);
        exit(-1);
    }
}
