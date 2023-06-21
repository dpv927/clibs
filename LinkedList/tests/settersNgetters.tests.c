#include <stdio.h>
#include <stdlib.h>
#include "../linkedList.h"
#include "settersNgetters.tests.h"

void test_Ll_getElementFrom() {
    // Create a new empty list
    LinkedList* list = Ll_createNewEmpty();

    int a = 1;
    int b = 2;
    int c = 3;

    // Add elements to the list
    Ll_addLast(list, &a);
    Ll_addLast(list, &b);
    Ll_addLast(list, &c);

    // Test getting elements from the list
    if (*(int*)Ll_getElementFrom(list, 0) != a ||
        *(int*)Ll_getElementFrom(list, 1) != b ||
        *(int*)Ll_getElementFrom(list, 2) != c) {
        printf("Failed test: Ll_getElementFrom() did not return the correct elements.\n");
        Ll_clear(list, NULL);
        free(list);
        exit(-1);
    }

    printf("Successful test: Ll_getElementFrom() returned the correct elements.\n");
    Ll_clear(list, NULL);
    free(list);
}

void test_Ll_setElementAt() {
    // Create a new empty list
    LinkedList* list = Ll_createNewEmpty();

    int a = 1;
    int b = 2;
    int c = 3;

    // Add elements to the list
    Ll_addLast(list, &a);
    Ll_addLast(list, &b);
    Ll_addLast(list, &c);

    int x = 10;
    int y = 20;
    int z = 30;

    // Set elements at specific indices in the list
    Ll_setElementAt(list, 0, &x); // Set at index 0
    Ll_setElementAt(list, 1, &y); // Set at index 1
    Ll_setElementAt(list, 2, &z); // Set at index 2

    // Test the updated elements in the list
    if (*(int*)Ll_getElementFrom(list, 0) != x ||
        *(int*)Ll_getElementFrom(list, 1) != y ||
        *(int*)Ll_getElementFrom(list, 2) != z) {
        printf("Failed test: Ll_setElementAt() did not update the elements correctly.\n");
        Ll_clear(list, NULL);
        free(list);
        exit(-1);
    }

    printf("Successful test: Ll_setElementAt() updated the elements correctly.\n");
    Ll_clear(list, NULL);
    free(list);
}
