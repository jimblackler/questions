#include <stdio.h>
#include <string.h>

void reverse(char *s) {
  char *front_ptr = s;
  char *end_ptr = s + strlen(s) - 1;
  while (front_ptr < end_ptr) {
    char tmp = *front_ptr;
    *front_ptr = *end_ptr;
    *end_ptr = tmp;
    front_ptr++;
    end_ptr--;
  }
}

int main(int argc, const char *argv[]) {

  char s[] = "Hello world";

  printf("%s\n", s);
  reverse(s);
  printf("%s\n", s);

  return 0;
}

