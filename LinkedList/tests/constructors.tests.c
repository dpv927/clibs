#include <stdio.h>
#include <stdlib.h>
#include "../linkedList.h"
#include "constructors.tests.h"

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
