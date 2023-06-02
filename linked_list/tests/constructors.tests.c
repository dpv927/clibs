#include <stdio.h>
#include <stdlib.h>
#include "../linkedList.h"

void test_Ll_createNewEmpty() {
  LinkedList* list = Ll_createNewEmpty();
  
  // Verify that an empty list has been created
  if (list != NULL && list->head == NULL && list->tail == NULL && list->len == 0) {
    printf("Successful test: Ll_createNewEmpty() created an empty list correctly.\n");
  } else {
    printf("Failed test: Ll_createNewEmpty() did not create an empty list correctly.\n");
    Ll_clear(list);
    free(list);
    exit(-1);
  }
  Ll_clear(list);
  free(list);
}

void test_Ll_createNewBased() {
    int x = 10;
    LinkedList* list = Ll_createNewBased(&x);

    // Verify that a list with an initial node and correct value has been created
    if (list != NULL && list->head != NULL && list->tail != NULL && list->len == 1) {
      int* initialValue = (int*)list->head->val;
      if (initialValue != NULL && *initialValue == x) {
        printf("Successful test: Ll_createNewBased() created a list with an initial node and correct value.\n");
      } else {
        printf("Failed test: Ll_createNewBased() did not assign the correct value to the initial node.\n");
        Ll_clear(list);
        free(list);
        exit(-1);
      }
    } else {
      printf("Failed test: Ll_createNewBased() did not create a list with an initial node correctly.\n");
      Ll_clear(list);
      free(list);
      exit(-1);
    }
  Ll_clear(list);
  free(list);
}

void test_Ll_createNewComparable() {
  // Suppose you have a comparator function called "compareIntegers"
  int(*compareIntegers)(void*, void*) = compareIntegers;
  LinkedList* list = Ll_createNewComparable(compareIntegers);

  // Verify that a list with the correct comparator has been created
  if (list != NULL && list->comparator == compareIntegers) {
    printf("Successful test: Ll_createNewComparable() created a list with the correct comparator.\n");
  } else {
    printf("Failed test: Ll_createNewComparable() did not create a list with the correct comparator.\n");
    Ll_clear(list);
    free(list);
    exit(-1);
  }
  Ll_clear(list);
  free(list);
}

void test_Ll_createNewBasedComparable() {
  int x = 10;
  // Suppose you have a comparator function called "compareIntegers"
  int(*compareIntegers)(void*, void*) = compareIntegers;
  LinkedList* list = Ll_createNewBasedComparable(compareIntegers, &x);

  // Verify that a list with an initial node, correct value, and comparator has been created
  if (list != NULL && list->head != NULL && list->tail != NULL && list->len == 1 && list->comparator == compareIntegers) {
    int* initialValue = (int*)list->head->val;
    if (initialValue != NULL && *initialValue == x) {
        printf("Successful test: Ll_createNewBasedComparable() created a list with an initial node, value, and comparator correctly.\n");
    } else {
      printf("Failed test: Ll_createNewBasedComparable() did not assign the correct value to the initial node.\n");
      Ll_clear(list);
      free(list);
      exit(-1);
    }
  } else {
    printf("Failed test: Ll_createNewBasedComparable() did not create a list with an initial node, value, and comparator correctly.\n");
    Ll_clear(list);
    free(list);  
    exit(-1);
  }
  Ll_clear(list);
  free(list);
}
