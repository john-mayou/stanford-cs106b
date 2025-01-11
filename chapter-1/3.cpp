#include <iostream>

int main() {
  int total = 0;
  for (int i = 1; i <= 100; i++) {
    total += i;
  }
  std::cout << "Total: " << total << std::endl;
  return 0;
}