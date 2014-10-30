#include <stdio.h>

int main(int argc, const char * argv[]) {
  // Create a list
  int l[] = {1, 2, 3};

  // Get length of the list
  printf("%lu", sizeof(l) / sizeof(int));

  // Return the second item
  printf("%i", l[1]);

  return 0;
}
