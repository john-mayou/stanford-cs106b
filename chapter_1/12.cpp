#include <cmath>
#include <iostream>

int main() {
  int radius;
  std::cout << "This program approximates the area of a quarter circle."
            << std::endl;
  std::cout << "Enter a circle radius: ";
  std::cin >> radius;

  const int numRectangles = 10000;
  const int radiusSqrd = std::pow(radius, 2);
  const long double width = (long double)(radius) / numRectangles;
  const long double widthHalf = width / 2;

  long double area = 0;
  for (int i = 0; i < numRectangles; i++) {
    long double midpoint = width * i + widthHalf;
    long double height = std::sqrt(radiusSqrd - std::pow(midpoint, 2));
    area += height * width;
  }

  std::cout << "Area: " << area << std::endl;
  std::cout << "Expected: " << (M_PI * std::pow(radius, 2)) / 4 << std::endl;

  return 0;
}