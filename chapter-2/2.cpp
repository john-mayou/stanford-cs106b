#include <iostream>

void metersToAmerican(int meters, int &feet, int &inches);

int main() {
  int meters, feet, inches;
  std::cout << "Meters: ";
  std::cin >> meters;
  metersToAmerican(meters, feet, inches);
  std::cout << "Feet: " << feet << std::endl;
  std::cout << "Inches: " << inches << std::endl;
  return 0;
}

void metersToAmerican(int meters, int &feet, int &inches) {
  int totalInches = meters / 0.0254;
  feet = totalInches / 12;
  inches = totalInches % 12;
}