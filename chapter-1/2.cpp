#include <iostream>

int main() {
  int m;
  std::cout << "Enter meters: ";
  std::cin >> m;
  float totalInches = m / 0.0254;
  std::cout << "totalInches: " << totalInches << std::endl;
  int feet = std::floor(totalInches / 12);
  float inches = totalInches - (feet * 12);
  std::cout << "Feet: " << feet << "; Inches: " << inches << std::endl;
  std::cout << "Feet: " << feet + (inches / 12.0) << std::endl;
  return 0;
}