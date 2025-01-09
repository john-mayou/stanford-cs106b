#include <iostream>

int main() {
  int c;
  std::cout << "Enter celsius: ";
  std::cin >> c;
  int f = (9 / 5.0) * c + 32;
  std::cout << "Fahrenheit: " << f << std::endl;
  return 0;
}