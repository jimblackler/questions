#import <Foundation/Foundation.h>

int main(const int argc, char **argv) {

  // Create a list
  NSMutableArray* l = [@[@1, @2, @3] mutableCopy];

  // Add an item
  [l addObject:@4];

  // Get length of the list
  NSLog(@"%lu", l.count);

  // Return the second item
  NSLog(@"%@", l[1]);

  // Remove the first item
  [l removeObjectAtIndex:0];

  // Clear the list
  [l removeAllObjects];

  return 0;
}
