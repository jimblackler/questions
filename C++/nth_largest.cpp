#include <iostream>
#include <queue>
#include <sys/time.h>

static void quickSort3Way(int *start, int *end, int *min) {
  if (end - start <= 1 || end < min)
    return;
  int pivot = *(start + (end - start) / 2);
  int *a = start;
  int *b = start;
  for (int *r = start; r < end; r++) {
    int v = *r;
    if (v <= pivot) {
      *r = *b++;
      if (v < pivot)
        *a++ = v;
    }
  }
  for (int *p = a; p < b; p++)
    *p = pivot;
  quickSort3Way(start, a, min);
  quickSort3Way(b, end, min);
}

static int nthLargestModifiedSort(const int array[], int size, int n) {
  int copy[size];
  memcpy(copy, array, sizeof(int) * size);
  quickSort3Way(copy, copy + size, &copy[size - n]);
  return copy[size - n];
}

static int nthLargestSort(const int array[], int size, int n) {
  int copy[size];
  memcpy(copy, array, sizeof(int) * size);
  std::sort(copy, copy + size);
  return copy[size - n];
}

static int nthLargestPriorityQueue(const int array[], int size, int n) {
  std::priority_queue<int> numbers;
  for (int i = 0; i < size; i++) {
    if(numbers.size() == n && -numbers.top() < array[i])
      numbers.pop();
    if (numbers.size() < n)
      numbers.push(-array[i]);
  }
  return -numbers.top();
}

static long long int getMicroseconds() {
  struct timeval time;
  gettimeofday(&time, 0);
  long long before = 1000000 * time.tv_sec + time.tv_usec;
  return before;
}

int mainz(int argc, const char *argv[]) {

  const int size = 100000;
  int array[size];
  srand(1);
  for (int i = 0; i < size; i++)
    array[i] = rand() % 10000;

  int n  = 10000;
  long long before = getMicroseconds();
  int result = nthLargestSort(array, size, n);
  printf("%d : %qi\n", result, getMicroseconds() - before);

  before = getMicroseconds();
  result = nthLargestPriorityQueue(array, size, n);
  printf("%d : %qi\n", result, getMicroseconds() - before);

  before = getMicroseconds();
  result = nthLargestModifiedSort(array, size, n);
  printf("%d : %qi\n", result, getMicroseconds() - before);

  return 0;
}

