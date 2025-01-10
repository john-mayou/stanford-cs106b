#include <iostream>
#include <limits>

const int SENTINEL = 0;

int main() {
  int max = std::numeric_limits<int>::min();
  int maxSet = false;
  std::cout << "Enter " << SENTINEL << " to signal the end of the list."
            << std::endl;
  while (true) {
    int value;
    std::cout << " ? ";
    std::cin >> value;
    if (value == SENTINEL) break;
    if (!maxSet || value > max) {
      max = value;
      maxSet = true;
    }
  }
  if (maxSet) {
    std::cout << "Maximum number provided was " << max << std::endl;
  } else {
    std::cout << "No numbers were provided." << std::endl;
  }
  return 0;
}