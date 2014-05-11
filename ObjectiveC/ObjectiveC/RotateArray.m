#import <Foundation/Foundation.h>

@interface RotateArray : NSObject

@end

@implementation RotateArray

+ (void)rotate:(NSMutableArray *)array by:(NSInteger)n {
  if (n < 0)
    n += array.count;
  NSMutableArray *arrayCopy =
      [NSMutableArray arrayWithArray:array];
  for (NSUInteger i = 0; i != [array count]; i++) {
    array[(i + n) % array.count] = arrayCopy[i];
  }
}


+ (void)rotate2:(NSMutableArray *)array by:(NSInteger)n {
  if (n < 0)
    n += array.count;

  while (n--) {
    NSObject *temp = array[[array count] - 1];
    for (NSUInteger i = [array count] - 1; i != 0; i--) {
      array[i] = array[i - 1];
    }
    array[0] = temp;
  }
}

+ (void)reverse:(NSMutableArray *)array
          start:(NSUInteger)s
            end:(NSUInteger)e {
  while (s < e) {
    [array exchangeObjectAtIndex:s++ withObjectAtIndex:e--];
  }
}

+ (void)rotate3:(NSMutableArray *)array by:(NSInteger)n {
  if (n < 0)
    n += array.count;
  // Reverse the array in place.
  [RotateArray reverse:array start:0 end:array.count - 1];
  // Re-reverse the first half.
  [RotateArray reverse:array start:0 end:n - 1];
  // Re-reverse the second half.
  [RotateArray reverse:array start:n end:array.count - 1];
}

+ (void)rotate4:(NSMutableArray *)array by:(NSInteger)n {
  if (n < 0)
    n += array.count;

  NSUInteger begin_at = 0;  // Element to begin each segment at
  NSUInteger count = array.count;
  while (count) {  // Count writes so we know when we're done
    // Begin each phase at the specified element
    NSUInteger i = begin_at;
    NSObject *prev = array[[array count] - n + i];
    do {
      NSObject *temp = array[i];
      // Copy the element a[i - n] (constrained) to a[n]
      array[i] = prev;
      // Previous value will be copied into next element
      prev = temp;
      i += n;  // Step by the rotate length
      // 'Wrap around' if we go over the array length
      i %= array.count;
      count--;
      // Continue until we hit the first element written
    } while (i != begin_at);
    begin_at++;  // Next phase should start offset by one
  }
}


@end


int main(const int argc, char **argv) {

  int len = 20;
  int n = -3;

  NSMutableArray *original = [NSMutableArray array];
  for (NSInteger i = 0; i != len; i++) {
    [original addObject:[NSNumber numberWithInt:i]];
  }
  NSMutableArray *array =
      [NSMutableArray arrayWithArray:original];

  [RotateArray rotate:array by:n];
  NSLog(@"%@\n", array);

  array = [NSMutableArray arrayWithArray:original];
  [RotateArray rotate2:array by:n];
  NSLog(@"%@\n", array);

  array = [NSMutableArray arrayWithArray:original];
  [RotateArray rotate3:array by:n];
  NSLog(@"%@\n", array);

  array = [NSMutableArray arrayWithArray:original];
  [RotateArray rotate4:array by:n];
  NSLog(@"%@\n", array);

  return 0;
}
