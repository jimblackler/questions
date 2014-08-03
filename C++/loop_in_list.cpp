#include <stdio.h>
#include <stdlib.h>
#import <time.h>
#import <set>

struct ListElement {

  ListElement *next;
};

ListElement *makeRandomList() {
  // Make between 1 and 100 elements.
  int numberElements = rand() % 100 + 1;

  ListElement *firstElement = new ListElement();
  ListElement *previousElement = firstElement;
  ListElement *loopElement = NULL;
  for (int count = 1; count != numberElements; count++) {
    ListElement *newElement = new ListElement();
    previousElement->next = newElement;
    if (rand() % 50 == 0) {
      // One in 50 chance this element becomes the loop element.
      loopElement = newElement;
    }
    previousElement = newElement;
  }
  previousElement->next = loopElement;
  return firstElement;
}

bool listLoopsSet(ListElement *ptr) {
  std::set<ListElement *> seen;
  while (ptr) {
    if (seen.find(ptr) != seen.end())
      return true;
    seen.insert(ptr);
    ptr = ptr->next;
  }
  return false;
}

bool listLoopsFollow(ListElement *ptr) {
  ListElement *leadPtr = ptr->next;
  while (leadPtr) {
    if (leadPtr == ptr)
      return true;
    leadPtr = leadPtr->next;
    if (!leadPtr)
      break;
    if (leadPtr == ptr)
      return true;
    leadPtr = leadPtr->next;
    ptr = ptr->next;
  }
  return false;
}

int main(int argc, const char *argv[]) {
  srand((unsigned int) time(0)); // Seed random number generator.
  ListElement *list = makeRandomList();
  if (listLoopsSet(list))
    printf("Set method: Loops\n");
  else
    printf("Set method: Doesn't loop\n");

  if (listLoopsFollow(list))
    printf("Follow method: Loops\n");
  else
    printf("Follow method: Doesn't loop\n");
  return 0;
}
