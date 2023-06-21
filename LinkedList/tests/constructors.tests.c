#include <stdio.h>
#include <stdlib.h>
#include "../linkedList.h"
#include "constructors.tests.h"

void test_Ll_createNewEmpty() {
  LinkedList* list = Ll_createNewEmpty();
  
  // A NULL list is a signal that indicates that malloc() failed
  // allocating a new list into memory.
  if(list == NULL) { printf("Cannot create a new list."); exit(-1); }

  // Test that the propierties have been initialized
  if(list->comparator == NULL && list->head == NULL && 
    list->tail == NULL && list->len == 0) {
    printf("Successful test: Ll_createNewEmpty() created an empty list correctly.\n");
  }
  else {
    printf("Failed test: Ll_createNewEmpty() did not create an empty list correctly.\n");
    Ll_clear(list, NULL);
    free(list);
    exit(-1);
  }

  Ll_clear(list, NULL);
  free(list);
}

// Create a comparable function for the next test
int cmp(void* a, void* b) { return 0; }

void test_Ll_createNewComparable() {
  LinkedList* list = Ll_createNewComparable(&cmp);
  
  // A NULL list is a signal that indicates that malloc() failed
  // allocating a new list into memory.
  if(list == NULL) { printf("Cannot create a new list."); exit(-1); }

  // Test that the propierties have been initialized
  if(list->comparator == &cmp && list->head == NULL && 
    list->tail == NULL && list->len == 0) {
    printf("Successful test: Ll_createNewComparable() created an empty comparable list correctly.\n");
  }
  else {
    printf("Failed test: Ll_createNewComparable() did not create an empty comparable list correctly.\n");
    Ll_clear(list, NULL);
    free(list);
    exit(-1);
  }

  Ll_clear(list, NULL);
  free(list);
}
