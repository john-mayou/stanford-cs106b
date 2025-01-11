#include <iostream>
#include <limits>

const int SENTINEL = 0;

int main() {
  int max = std::numeric_limits<int>::min();
  int max2 = std::numeric_limits<int>::min();
  bool maxSet = false;
  bool max2Set = false;
  std::cout << "Enter " << SENTINEL << " to signal the end of the list."
            << std::endl;
  while (true) {
    int value;
    std::cout << " ? ";
    std::cin >> value;
    if (value == SENTINEL) break;
    if (!maxSet) {
      max = value;
      maxSet = true;
    } else if (!max2Set) {
      if (value > max) {
        max2 = max;
        max = value;
      } else {
        max2 = value;
      }
      max2Set = true;
    } else if (value > max) {
      max2 = max;
      max = value;
    } else if (value > max2) {
      max2 = value;
    }
  }
  if (maxSet && max2Set) {
    std::cout << "Largest number: " << max << std::endl;
    std::cout << "Second largest number: " << max2 << std::endl;
  } else if (maxSet) {
    std::cout << "Largest number: " << max << std::endl;
    std::cout << "No other number was provided." << std::endl;
  } else if (max2Set) {
    throw std::runtime_error("max should always be set before max2");
  } else {
    std::cout << "No numbers were provided." << std::endl;
  }
  return 0;
}