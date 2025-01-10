#include <cmath>
#include <iostream>

int main() {
  const char add = '+';
  const char sub = '-';
  std::cout << "This program demonstates the Leibniz's series." << std::endl;
  long double result = 1;
  float currentDen = 3.0;
  char currentOp = sub;
  int step = 1;
  int steps = 10000;
  while (step <= steps) {
    switch (currentOp) {
      case add:
        result += (1 / currentDen);
        currentOp = sub;
        break;
      case sub:
        result -= (1 / currentDen);
        currentOp = add;
        break;
      default:
        throw std::runtime_error("Invalid current operation: " +
                                 std::to_string(currentOp));
    }
    currentDen += 2.0;
    step++;
  }
  std::cout << "Result: " << result << std::endl;
  std::cout << "PI / 4: " << M_PI_4 << std::endl;
}