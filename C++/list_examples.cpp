#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {

  // Create a list
  std::vector<int> l = {1, 2, 3};

  // Add an item
  l.push_back(4);

  // Get length of the list
  printf("%lu\n", l.size());

  // Return the second item
  printf("%d\n", l[1]);

  // Remove the first item
  l.erase(l.begin());
  
  // Clear the list
  l.clear();

  return 0;
}
