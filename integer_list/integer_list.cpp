#include <iostream>

const int SENTINEL = 0;

int main() {
  std::cout << "This program adds a list of numbers." << std::endl;
  std::cout << "Use " << SENTINEL << " to signal the end." << std::endl;
  int total = 0;
  while (true) {
    int value;
    std::cout << "Enter a value: ";
    std::cin >> value;
    if (value == SENTINEL) break;
    total += value;
  }
  std::cout << "The total is " << total << std::endl;
  return 0;
}