#include <stdio.h>
#include "constructor.tests.h"
#include "queuebasics.tests.h"

int main() {
  printf("Constructor tests --------------\n");
  test_Q_createNew();
  
  printf("\nQueue utilities tests ----------\n");
  test_Q_enqueue_and_Q_dequeue();
  test_Q_isEmpty();
  test_Q_clear();
  return 0;
}
