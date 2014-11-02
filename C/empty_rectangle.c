#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>

long long int getMicroseconds() {
  struct timeval time;
  gettimeofday(&time, 0);
  long long before = 1000000 * time.tv_sec + time.tv_usec;
  return before;
}

const int size = 20;

struct Rectangle {
  int left;
  int right;
  int top;
  int bottom;
};

bool isEmpty(bool grid[size][size], int left, int right,
    int top, int bottom) {
  for (int x = left; x <= right; x++) {
    for (int y = top; y <= bottom; y++) {
      if (grid[y][x])
        return false;
    }
  }
  return true;
}

struct Rectangle *solve(bool grid[size][size]) {
  struct Rectangle *largest = malloc(sizeof(struct Rectangle));
  int largestArea = 0;
  for (int left = 0; left != size; left++) {
    for (int right = left; right != size; right++) {
      for (int top = 0; top != size; top++) {
        for (int bottom = top; bottom != size; bottom++) {
          int area = (right - left + 1) * (bottom - top + 1);
          if (area < largestArea)
            continue;
          if (!isEmpty(grid, left, right, top, bottom))
            continue;
          largestArea = area;
          largest->left = left;
          largest->right = right;
          largest->top = top;
          largest->bottom = bottom;
        }
      }
    }
  }
  return largest;
}

void solvePart(bool grid[size][size],
    int left, int right, int top, int bottom,
    struct Rectangle *best) {
  int bestArea = (best->right - best->left + 1) *
      (best->bottom - best->top + 1);
  int area = (right - left + 1) * (bottom - top + 1);
  if (area < bestArea)
    return;

  for (int x = left; x <= right; x++) {
    for (int y = top; y <= bottom; y++) {
      if (!grid[y][x])
        continue;
      solvePart(grid, left, x - 1, top, bottom, best);
      solvePart(grid, x + 1, right, top, bottom, best);
      solvePart(grid, left, right, top, y - 1, best);
      solvePart(grid, left, right, y + 1, bottom, best);
      return;
    }
  }
  best->left = left;
  best->right = right;
  best->top = top;
  best->bottom = bottom;
};

struct Rectangle *solve2(bool grid[size][size]) {
  struct Rectangle *largest = malloc(sizeof(struct Rectangle));
  largest->left = 0;
  largest->right = -1;
  largest->top = 0;
  largest->bottom = -1;
  solvePart(grid, 0, size - 1, 0, size - 1, largest);
  return largest;
}



int main(int argc, const char *argv[]) {

  srand(11);
  bool a[size][size];
  for (int idx = 0; idx != 30; idx++) {
    a[rand() % size][rand() % size] = true;
  }
  long long before = getMicroseconds();
  struct Rectangle *rectangle = solve(a);
  long long time = getMicroseconds() - before;
  printf("%d %d %d %d (%lld)\n",
      rectangle->left, rectangle->right,
      rectangle->top, rectangle->bottom, time);
  free(rectangle);

  before = getMicroseconds();
  rectangle = solve2(a);
  time = getMicroseconds() - before;
  printf("%d %d %d %d (%lld)\n",
      rectangle->left, rectangle->right,
      rectangle->top, rectangle->bottom, time);
  free(rectangle);

  return 0;
}
