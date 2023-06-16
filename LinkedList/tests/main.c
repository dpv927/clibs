#include <stdio.h>

int main() {
  #include "constructors.tests.h"
  printf("Constructors Tests --------------------\n");
  test_Ll_createNewEmpty();
  test_Ll_createNewBased();
  test_Ll_createNewComparable();
  test_Ll_createNewBasedComparable();

  #include "adders.tests.h"
  printf("\nAdders Tests ------------------------\n");
  test_Ll_addFirst();
  test_Ll_addLast();
  test_Ll_addAt();

  #include "removers.tests.h"
  printf("\nRemovers Tests ----------------------\n");
  test_Ll_removeFirst();
  test_Ll_removeLast();
  test_Ll_removeElementAt();

  #include "utils.tests.h"
  printf("\nUtils Tests -------------------------\n");
  test_Ll_clear();
  test_Ll_contains();
  test_Ll_isEmpty();

  #include "indexers.tests.h"
  printf("\nIndexers Tests ----------------------\n");
  test_Ll_lastIndexOf();
  test_Ll_indexOf();

  #include "settersNgetters.tests.h"
  printf("\nSetters & Getters Tests --------------\n");
  test_Ll_setElementAt();
  test_Ll_getElementFrom();  
  return 0;
}
