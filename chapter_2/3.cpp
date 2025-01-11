#include <iostream>

int roundNum(double n);
void testRoundNum(double n);

int main() {
  testRoundNum(-2);
  testRoundNum(-1.7);
  testRoundNum(-1.5);
  testRoundNum(-1.2);
  testRoundNum(0);
  testRoundNum(1.2);
  testRoundNum(1.5);
  testRoundNum(1.7);
  testRoundNum(2);
  return 0;
}

int roundNum(double n) { return (n > 0) ? int(n + 0.5) : int(n - 0.5); }

void testRoundNum(double n) {
  std::cout << "roundNum(" << n << ") = " << roundNum(n) << std::endl;
}
