#include <iostream>

double randReal();

int main() {
  int trials;
  std::cout << "Enter number of trials: ";
  std::cin >> trials;
  double sum = 0;
  for (int i = 0; i < trials; i++) {
    sum += randReal();
  }
  std::cout << "Average: " << (sum / trials) << std::endl;
  return 0;
}

double randReal() { return rand() / (double(RAND_MAX) + 1); }