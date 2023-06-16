#include <stdio.h>
#include <stdlib.h>
#include "constructor.tests.h"

void test_Q_createNew() {
    Queue* queue = Q_createNew();

    if (queue != NULL && queue->list != NULL && Q_isEmpty(queue)) {
        printf("Successful test: Q_createNew() created a new empty queue.\n");
    } else {
        printf("Failed test: Q_createNew() did not create a new empty queue correctly.\n");
        Q_clear(queue);
        free(queue);
        exit(-1);
    }
}
