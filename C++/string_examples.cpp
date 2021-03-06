#include <iostream>

int main(int argc, const char * argv[]) {

  // Make a string
  std::string s("Hello");

  // Find length of a string
  std::cout << s.length() << std::endl;

  // Compare two strings
  std::string s2("Hello 2");
  std::cout << (s == s2) << std::endl;

  // Search for a substring
  s2 = std::string("el");
  std::cout << s.find(s2) << std::endl;

  // Make a substring
  size_t b = 1;
  size_t e = 3;
  s2 = s.substr(b, e);
  std::cout << s2 << std::endl;

  return 0;
}
