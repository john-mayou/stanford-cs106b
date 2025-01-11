#include <iostream>
#include <limits>

const int SENTINEL = -1;

int main() {
  int scoreTotal = 0;
  int scoreCount = 0;
  std::cout << "This program calculates the average of test scores."
            << std::endl;
  while (true) {
    int score;
    std::cout << "Enter a score: ";
    std::cin >> score;
    if (score == SENTINEL) break;
    scoreTotal += score;
    scoreCount++;
  }
  std::cout << "Average score: " << scoreTotal / float(scoreCount) << std::endl;
  return 0;
}