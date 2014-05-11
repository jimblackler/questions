#include <stdio.h>
#include <string.h>

static void reverse_substring(char *front_ptr, char *end_ptr) {
  while (front_ptr < end_ptr) {
    char tmp = *front_ptr;
    *front_ptr = *end_ptr;
    *end_ptr = tmp;
    front_ptr++;
    end_ptr--;
  }
}

static void reverse(char *s) {
  // Reverse the string.
  reverse_substring(s, s + strlen(s) - 1);

  // Re-reverse the words.
  while(*s) {
    if (*s == ' ') {
      // Find start of word.
      s++;
    } else {
      // Find end of word.
      char *end = s;
      while (*(end + 1) && *(end + 1) != ' ') {
        end++;
      }
      reverse_substring(s, end);
      s = end + 1;
    }
  }
}

int main(int argc, const char *argv[]) {

  char s[] = "One small step for a man";

  printf("%s\n", s);
  reverse(s);
  printf("%s\n", s);

  return 0;
}

