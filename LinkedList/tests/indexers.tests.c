#include <stdio.h>
#include <stdlib.h>
#include "../linkedList.h"
#include "indexers.tests.h"

int compareInt2(void* a, void* b) {
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

void test_Ll_lastIndexOf() {
    // Create a new list with integer comparator
    LinkedList* list = Ll_createNewComparable(compareInt2);

    int a = 1;
    int b = 2;
    int c = 1;

    // Add elements to the list
    Ll_addLast(list, &a);
    Ll_addLast(list, &b);
    Ll_addLast(list, &c);

    // Test last index of elements in the list
    if (Ll_lastIndexOf(list, &a) != 2 ||
        Ll_lastIndexOf(list, &b) != 1 ||
        Ll_lastIndexOf(list, &c) != 2) {
        printf("Failed test: Ll_lastIndexOf() did not return the correct results.\n");
        Ll_clear(list, NULL);
        free(list);
        exit(-1);
    }

    // Test last index of element not in the list
    int d = 3;
    if (Ll_lastIndexOf(list, &d) != -1) {
        printf("Failed test: Ll_lastIndexOf() did not return the correct result for element not in the list.\n");
        Ll_clear(list, NULL);
        free(list);
        exit(-1);
    }

    printf("Successful test: Ll_lastIndexOf() returned the correct results.\n");
    Ll_clear(list, NULL);
    free(list);
}

void test_Ll_indexOf() {
    // Create a new list with integer comparator
    LinkedList* list = Ll_createNewComparable(compareInt2);

    int a = 1;
    int b = 2;
    int c = 1;

    // Add elements to the list
    Ll_addLast(list, &a);
    Ll_addLast(list, &b);
    Ll_addLast(list, &c);

    // Test index of elements in the list
    if (Ll_indexOf(list, &a) != 0 ||
        Ll_indexOf(list, &b) != 1 ||
        Ll_indexOf(list, &c) != 0) {
        printf("Failed test: Ll_indexOf() did not return the correct results.\n");
        Ll_clear(list, NULL);
        free(list);
        exit(-1);
    }

    // Test index of element not in the list
    int d = 3;
    if (Ll_indexOf(list, &d) != -1) {
        printf("Failed test: Ll_indexOf() did not return the correct result for element not in the list.\n");
        Ll_clear(list, NULL);
        free(list);
        exit(-1);
    }

    printf("Successful test: Ll_indexOf() returned the correct results.\n");
    Ll_clear(list, NULL);
    free(list);
}
