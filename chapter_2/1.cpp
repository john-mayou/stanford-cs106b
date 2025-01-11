#include <iostream>

double celsiusToFahrenheit(double c);

int main() {
  int c;
  std::cout << "Enter celsius: ";
  std::cin >> c;
  std::cout << "Fahrenheit: " << celsiusToFahrenheit(c) << std::endl;
  return 0;
}

double celsiusToFahrenheit(double c) { return (9 / 5.0) * c + 32; }