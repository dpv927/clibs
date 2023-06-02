#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#define GREATER_THAN 1
#define LESS_THAN -1
#define EQUAL_TO 0

int comparer(int* x, int* y) {
    int xVal = *x;
    int yVal = *y;
    return (xVal > yVal) ? GREATER_THAN : ((xVal < yVal) ? LESS_THAN : EQUAL_TO);
}

int main() {
    int x = 0, y = 1, z = 2;
    LinkedList* list = Ll_createNewComparable(&comparer);
    Ll_addLast(list, &x);
    Ll_addLast(list, &y);
    Ll_addLast(list, &z);

    printf("[ ");
    if (list->head != NULL) {
        Node* tmp = list->head;
        while (tmp != NULL) {
            int* x = (int*) tmp->val;
            printf("%d ", *x);
            tmp = tmp->chld;
        }
    }
    printf("]\n\n");

    Ll_clear(list);
    free(list);
    return 0;
}