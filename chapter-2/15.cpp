#include <iostream>

const int target = 3;

bool flip();
double randReal();
void initRand();

int main() {
  std::cout << "This program prints the number of flips it took to get "
            << target << " consecutive heads." << std::endl;
  int flips = 0;
  int consecutive = 0;
  while (consecutive != target) {
    if (flip()) {
      std::cout << "heads" << std::endl;
      consecutive++;
    } else {
      std::cout << "tails" << std::endl;
      consecutive = 0;
    }
    flips++;
  }
  std::cout << "It took " << flips << " flips." << std::endl;
  return 0;
}

bool flip() { return randReal() < 0.5; }

double randReal() {
  initRand();
  return rand() / (double(RAND_MAX) + 1);
}

void initRand() {
  static bool initialized = false;
  if (!initialized) {
    srand(int(time(NULL)));
    initialized = true;
  }
}