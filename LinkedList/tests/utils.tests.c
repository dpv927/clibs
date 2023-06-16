#include <stdio.h>
#include <stdlib.h>
#include "../linkedList.h"
#include "utils.tests.h"

void test_Ll_clear() {
    // Create a new list
    LinkedList* list = Ll_createNewEmpty();

    int a = 1;
    int b = 2;
    int c = 3;

    // Add elements to the list
    Ll_addLast(list, &a);
    Ll_addLast(list, &b);
    Ll_addLast(list, &c);

    // Clear the list
    Ll_clear(list);

    // Verify that the list is empty
    if (list->len != 0 || list->head != NULL || list->tail != NULL) {
        printf("Failed test: Ll_clear() did not clear the list correctly.\n");
        free(list);
        exit(-1);
    }

    printf("Successful test: Ll_clear() cleared the list correctly.\n");
    free(list);
}

int compareInt(void* a, void* b) {
    int* intA = (int*)a;
    int* intB = (int*)b;

    if (*intA < *intB) {
        return -1;
    } else if (*intA > *intB) {
        return 1;
    } else {
        return 0;
    }
}

void test_Ll_contains() {
    // Create a new list with integer comparator
    LinkedList* list = Ll_createNewComparable(&compareInt);

    int a = 1;
    int b = 2;
    int c = 3;

    // Add elements to the list
    Ll_addLast(list, &a);
    Ll_addLast(list, &b);
    Ll_addLast(list, &c);

    // Test if elements are contained in the list
    if (Ll_contains(list, &a) != 1 ||
        Ll_contains(list, &b) != 1 ||
        Ll_contains(list, &c) != 1 ||
        Ll_contains(list, &b) != 1) {
        printf("Failed test: Ll_contains() did not return the correct results.\n");
        Ll_clear(list);
        free(list);
        exit(-1);
    }

    // Test if element not in the list is correctly reported as not contained
    int d = 4;
    if (Ll_contains(list, &d) != 0) {
        printf("Failed test: Ll_contains() did not return the correct result for element not in the list.\n");
        Ll_clear(list);
        free(list);
        exit(-1);
    }

    printf("Successful test: Ll_contains() returned the correct results.\n");

    Ll_clear(list);
    free(list);
}

void test_Ll_isEmpty() {
    // Create a new empty list
    LinkedList* list = Ll_createNewEmpty();

    // Verify that the list is empty
    if (Ll_isEmpty(list) != 1) {
        printf("Failed test: Ll_isEmpty() did not return the correct result for an empty list.\n");
        free(list);
        exit(-1);
    }

    // Add an element to the list
    int a = 1;
    Ll_addLast(list, &a);

    // Verify that the list is not empty
    if (Ll_isEmpty(list) != 0) {
        printf("Failed test: Ll_isEmpty() did not return the correct result for a non-empty list.\n");
        Ll_clear(list);
        free(list);
        exit(-1);
    }

    printf("Successful test: Ll_isEmpty() returned the correct results.\n");

    Ll_clear(list);
    free(list);
}
