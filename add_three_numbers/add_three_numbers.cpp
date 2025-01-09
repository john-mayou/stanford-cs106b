#include <iostream>

int main() {
  double n1, n2, n3;
  std::cout << "This program adds three numbers." << std::endl;

  std::cout << "First number: ";
  std::cin >> n1;
  std::cout << "Second number: ";
  std::cin >> n2;
  std::cout << "Third number: ";
  std::cin >> n3;

  double sum = n1 + n2 + n3;
  std::cout << "The total is: " << sum << std::endl;

  return 0;
}