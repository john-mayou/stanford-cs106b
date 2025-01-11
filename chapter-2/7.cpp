#include <iostream>

double sqrt(double n);

int main() {
  std::cout << "sqrt(4) = " << sqrt(4) << std::endl;
  std::cout << "sqrt(16) = " << sqrt(16) << std::endl;
  std::cout << "sqrt(25) = " << sqrt(25) << std::endl;
  std::cout << "sqrt(64) = " << sqrt(64) << std::endl;
  std::cout << "sqrt(81) = " << sqrt(81) << std::endl;
  return 0;
}

double sqrt(double n) {
  double guess = n / 2;
  while (true) {
    double newGuess = (guess + (n / guess)) / 2;
    if (newGuess == guess) return guess;
    guess = newGuess;
  }
}