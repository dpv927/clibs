#include <stdio.h>
#include <stdlib.h>
#include "constructors.tests.h"
#include "adders.tests.h"

int main() {
  printf("Constructors Tests --------------------\n");
  test_Ll_createNewEmpty();
  test_Ll_createNewBased();
  test_Ll_createNewComparable();
  test_Ll_createNewBasedComparable();

  printf("\nAdders Tests --------------------\n");
  test_Ll_addFirst();
  test_Ll_addLast();
  test_Ll_addAt();
  return 0;
}
