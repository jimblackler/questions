#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {

  // Make a string
  char s[] = "Hello";

  // Find length of a string
  printf("%zu\n", strlen(s));

  // Compare two strings
  char *s2 = "Hello";
  printf("%d\n", strcmp(s, s2));

  // Search for a substring
  s2 = "el";
  printf("%zu\n", strstr(s, s2) - s);

  return 0;
}
