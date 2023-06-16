#include <stdio.h>
#include <stdlib.h>
#include "../linkedList.h"
#include "adders.tests.h"

void test_Ll_addFirst() {
  // Create a new empty list
  LinkedList* list = Ll_createNewEmpty();

  int x = 10;
  int y = 20;
  int z = 30;

  // Add elements to the beginning of the list
  Ll_addFirst(list, &x);
  Ll_addFirst(list, &y);
  Ll_addFirst(list, &z);

  // Verify the list content and length
  if (list->head != NULL && list->tail != NULL && list->len == 3) {
    int* firstValue = (int*)list->head->val;
    int* secondValue = (int*)list->head->chld->val;
    int* thirdValue = (int*)list->head->chld->chld->val;

    if (firstValue != NULL && *firstValue == z &&
      secondValue != NULL && *secondValue == y &&
      thirdValue != NULL && *thirdValue == x) {
      printf("Successful test: Ll_addFirst() added elements to the beginning of the list correctly.\n");
    } else {
      printf("Failed test: Ll_addFirst() did not add elements to the beginning of the list correctly.\n");
      Ll_clear(list);
      free(list);
      exit(-1);
    }
  } else {
    printf("Failed test: Ll_addFirst() did not update the list properties correctly.\n");
    Ll_clear(list);
    free(list);
    exit(-1);
  }
  Ll_clear(list);
  free(list);
}

void test_Ll_addLast() {
  // Create a new empty list
  LinkedList* list = Ll_createNewEmpty();

  int x = 10;
  int y = 20;
  int z = 30;

  // Add elements to the end of the list
  Ll_addLast(list, &x);
  Ll_addLast(list, &y);
  Ll_addLast(list, &z);

  // Verify the list content and length
  if (list->head != NULL && list->tail != NULL && list->len == 3) {
    int* firstValue = (int*)list->head->val;
    int* secondValue = (int*)list->head->chld->val;
    int* thirdValue = (int*)list->tail->val;

    if (firstValue != NULL && *firstValue == x &&
      secondValue != NULL && *secondValue == y &&
      thirdValue != NULL && *thirdValue == z) {
      printf("Successful test: Ll_addLast() added elements to the end of the list correctly.\n");
    } else {
      printf("Failed test: Ll_addLast() did not add elements to the end of the list correctly.\n");
      Ll_clear(list);
      free(list);
      exit(-1);
    }
  } else {
    printf("Failed test: Ll_addLast() did not update the list properties correctly.\n");
    Ll_clear(list);
    free(list);
    exit(-1);
  }
  Ll_clear(list);
  free(list);
}

void test_Ll_addAt() {
  // Create a new empty list
  LinkedList* list = Ll_createNewEmpty();

  int x = 10;
  int y = 20;
  int z = 30;

  // Add elements at specific indices in the list
  Ll_addAt(list, 0, &x); // Add at index 0
  Ll_addAt(list, 1, &z); // Add at index 1
  Ll_addAt(list, 1, &y); // Add at index 1 (middle)

  // Verify the list content and length
  if (list->head != NULL && list->tail != NULL && list->len == 3) {
    int* firstValue = (int*)list->head->val;
    int* secondValue = (int*)list->head->chld->val;
    int* thirdValue = (int*)list->tail->val;

    if (firstValue != NULL && *firstValue == x &&
      secondValue != NULL && *secondValue == y &&
      thirdValue != NULL && *thirdValue == z) {
      printf("Successful test: Ll_addAt() added elements at specific indices in the list correctly.\n");
    } else {
      printf("Failed test: Ll_addAt() did not add elements at specific indices in the list correctly.\n");
      Ll_clear(list);
      free(list);
      exit(-1);
    }
  } else {
    printf("Failed test: Ll_addAt() did not update the list properties correctly.\n");
    Ll_clear(list);
    free(list);
    exit(-1);
  }
  Ll_clear(list);
  free(list);
}
