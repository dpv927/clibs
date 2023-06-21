#include <stdio.h>
#include <stdlib.h>
#include "../linkedList.h"
#include "removers.tests.h"

void test_Ll_removeFirst() {
    // Create a new list
    LinkedList* list = Ll_createNewEmpty();

    int a = 1;
    int b = 2;
    int c = 3;

    // Add elements to the list
    Ll_addLast(list, &a);
    Ll_addLast(list, &b);
    Ll_addLast(list, &c);

    // Verify the list content before removing the first element
    if (list->len != 3 || *(int*)list->head->val != a || *(int*)list->tail->val != c) {
        printf("Failed test: Ll_removeFirst() did not initialize the list correctly.\n");
        Ll_clear(list, NULL);
        free(list);
        exit(-1);
    }

    // Remove the first element
    void* removed = Ll_removeFirst(list);

    // Verify the list content after removing the first element
    if (list->len != 2 || *(int*)list->head->val != b || *(int*)list->tail->val != c || *(int*)removed != a) {
        printf("Failed test: Ll_removeFirst() did not remove the first element correctly.\n");
        Ll_clear(list, NULL);
        free(list);
        exit(-1);
    }

    printf("Successful test: Ll_removeFirst() removed the first element correctly.\n");
    Ll_clear(list, NULL);
    free(list);
}

void test_Ll_removeLast() {
    // Create a new list
    LinkedList* list = Ll_createNewEmpty();

    int a = 1;
    int b = 2;
    int c = 3;

    // Add elements to the list
    Ll_addLast(list, &a);
    Ll_addLast(list, &b);
    Ll_addLast(list, &c);

    // Verify the list content before removing the last element
    if (list->len != 3 || *(int*)list->head->val != a || *(int*)list->tail->val != c) {
        printf("Failed test: Ll_removeLast() did not initialize the list correctly.\n");
        Ll_clear(list, NULL);
        free(list);
        exit(-1);
    }

    // Remove the last element
    void* removed = Ll_removeLast(list);

    // Verify the list content after removing the last element
    if (list->len != 2 || *(int*)list->head->val != a || *(int*)list->tail->val != b || *(int*)removed != c) {
        printf("Failed test: Ll_removeLast() did not remove the last element correctly.\n");
        Ll_clear(list, NULL);
        free(list);
        exit(-1);
    }

    printf("Successful test: Ll_removeLast() removed the last element correctly.\n");
    Ll_clear(list, NULL);
    free(list);
}

void test_Ll_removeElementAt() {
    // Create a new list
    LinkedList* list = Ll_createNewEmpty();

    int a = 1;
    int b = 2;
    int c = 3;

    // Add elements to the list
    Ll_addLast(list, &a);
    Ll_addLast(list, &b);
    Ll_addLast(list, &c);

    // Verify the list content before removing the element at index 1
    if (list->len != 3 || *(int*)list->head->val != a || *(int*)list->tail->val != c) {
        printf("Failed test: Ll_removeElementAt() did not initialize the list correctly.\n");
        Ll_clear(list, NULL);
        free(list);
        exit(-1);
    }

    int index = 1;
    void* removed = Ll_removeElementAt(list, index);

    // Verify the list content after removing the element at index 1
    if (list->len != 2 || *(int*)list->head->val != a || *(int*)list->tail->val != c || *(int*)removed != b) {
        printf("Failed test: Ll_removeElementAt() did not remove the element at index %d correctly.\n", index);
        Ll_clear(list, NULL);
        free(list);
        exit(-1);
    }

    printf("Successful test: Ll_removeElementAt() removed the element at index %d correctly.\n", index);
    Ll_clear(list, NULL);
    free(list);
}

