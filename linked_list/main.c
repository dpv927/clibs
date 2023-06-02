#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main() {
    // Create a empty list
    LinkedList* list = Ll_createNewEmpty();
    
    // Add some elements
    int x = 0, y = 1, z = 2;
    Ll_addLast(list, &x);
    Ll_addLast(list, &y);
    Ll_addLast(list, &z);

    // Print the list elements in order using the
    // LinkedList fields:
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
