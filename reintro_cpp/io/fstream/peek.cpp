#include <iostream>
#include <sstream>
int main() {
  std::istringstream s1("Hello, world.");
  char c1 = s1.peek();
  char c2 = s1.get();
  std::cout << "Peeked: " << c1 << " got: " << c2 << '\n';
  char c3 = s1.peek();
  char c4 = s1.get();
  std::cout << "Peeked: " << c3 << " got: " << c4 << '\n';
}