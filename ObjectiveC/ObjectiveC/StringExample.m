#import <Foundation/Foundation.h>

int main(const int argc, char **argv) {

  // Make a string
  NSString *s= @"Hello";

  // Find length of a string
  NSLog(@"%zu\n", s.length);

  // Compare two strings
  NSString *s2 = @"Hello";
  NSLog(@"%d\n", [s isEqualToString:s2]);

  // Search for a substring
  s2 = @"el";
  NSLog(@"%zu\n", [s rangeOfString:s2].location);

  // Make a substring
  size_t b = 1;
  size_t e = 3;
  s2 = [s substringWithRange:NSMakeRange(b, e)];
  NSLog(@"%@\n", s2);

  return 0;
}
