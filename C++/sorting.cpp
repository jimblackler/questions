#include <assert.h>
#include <iostream>
#include <queue>
#include <sys/time.h>


static void bubbleSort(int *start, int *end) {
  for (int *endPtr = end; end >= start; end--) {
    for (int *ptr = start; &ptr[1] < endPtr; ptr++) {
      if (*ptr > ptr[1])
        std::swap(*ptr, ptr[1]);
    }
  }
}

static void quicksort3Way(int *start, int *end) {
  if (end - start <= 1)
    return;
  int pivot = *(start + (end - start) / 2);
  int *a = start;  // [start, a) is <pivot region
  int *b = start;  // [b, ptr) is >pivot region
  for (int *ptr = start; ptr < end; ptr++) {
    int v = *ptr;
    if (v > pivot)
      continue;
    *ptr = *b++;  // >pivot region shifted
    if (v < pivot)
      *a++ = v;  // <pivot region extended
  }
  for (int *ptr = a; ptr < b; ptr++)
    *ptr = pivot;  // Fill =pivot region
  quicksort3Way(start, a);  // Sort <pivot region
  quicksort3Way(b, end);  // Sort >pivot region
}



static void quicksort3WayTail(int *start, int *end) {
  while (end - start > 1) {
    int pivot = *(start + (end - start) / 2);
    int *a = start;  // [start, a) is <pivot region
    int *b = start;  // [b, ptr) is >pivot region
    for (int *ptr = start; ptr < end; ptr++) {
      int v = *ptr;
      if (v > pivot)
        continue;
      *ptr = *b++;  // >pivot region shifted
      if (v < pivot)
        *a++ = v;  // <pivot region extended
    }
    for (int *ptr = a; ptr < b; ptr++)
      *ptr = pivot;  // Fill =pivot region
    quicksort3Way(start, a);  // Sort <pivot region
    start = b;  // Sort >pivot region next iteration
  }
}

static void insertionSort(int *start, int *end) {
  for (int *fwd = start + 1; fwd < end; fwd++) {
    int value = *fwd;
    int *rev;
    for (rev = fwd;
         rev > start && rev[-1] > value; rev--)
      *rev = rev[-1];
    *rev = value;
  }
}

static void quicksort(int *start, int *end) {
  int pivot = *(start + (end - start) / 2);
  int *divider = start;
  for (int *ptr = start; ptr < end; ptr++) {
    if (*ptr < pivot)
      std::swap(*ptr, *divider++);
  }
  if (start == divider || divider == end)
    return insertionSort(start, end);

  quicksort(start, divider);
  quicksort(divider, end);
}

static void check(const int array[], size_t size) {
  int previous = -1;
  for (int i = 0; i < size; i++) {
    assert(array[i] >= previous);
    previous = array[i];
  }
}

void check_eq(const int array1[], const int array2[], size_t size) {
  for (int i = 0; i < size; i++)
    assert(array1[i] == array2[i]);
}

static long long int getMicroseconds() {
  struct timeval time;
  gettimeofday(&time, 0);
  long long before = 1000000 * time.tv_sec + time.tv_usec;
  return before;
}

void testMethod(const char *name, void method(int *, int *),
    size_t size, const int *original, int *reference) {
  int copy[size];
  memcpy(copy, original, sizeof(int) * size);
  long long before = getMicroseconds();
  method(copy, copy + size);
  printf("%s:\t%qi\n", name, getMicroseconds() - before);
  check(copy, size);
  check_eq(reference, copy, size);
}

int main(int argc, const char *argv[]) {
  const size_t size = 2000000;
  int *original = (int *) malloc(size * sizeof(int));
  srand(1);
  for (size_t i = 0; i < size; i++)
    original[i] = rand() % 2000000;
  int *reference = (int *) malloc(size * sizeof(int));
  memcpy(reference, original, sizeof(int) * size);
  std::sort(reference, reference + size);

  testMethod("std::sort", std::sort, size, original, reference);
//  testMethod("bubbleSort", bubbleSort, size, original, reference);
//  testMethod("insertionSort", insertionSort, size, original, reference);
  testMethod("quicksort", quicksort, size, original, reference);
  testMethod("quicksort3Way", quicksort3Way, size, original, reference);
  testMethod("quicksort3WayTail", quicksort3WayTail, size, original, reference);

  return 0;
}

