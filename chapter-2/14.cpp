#include <cmath>
#include <iostream>

const int darts = 10000;

double randInclusive(double low, double high);

int main() {
  std::cout << "This program demonstrates the Monte Carlo integration."
            << std::endl;
  int inCircle = 0;
  for (int i = 0; i < darts; i++) {
    double x = randInclusive(-1, 1);
    double y = randInclusive(-1, 1);
    if (std::pow(x, 2) + std::pow(y, 2) < 1) inCircle++;
  }
  std::cout << "Pi approximation: " << (inCircle / double(darts)) * 4
            << std::endl;
  return 0;
}

/**
 * Returns a floating point value between low (inclusive) and high (inclusive).
 */
double randInclusive(double low, double high) {
  double d = double(rand()) / RAND_MAX;  // normalize: 0 <= d <= 1
  double s = d * (high - low);  // scale: low <= s <= high (s not correct yet)
  double t = s + low;           // translate: low <= s <= high
  return t;
}