#include <iostream>

const double decayP = 0.5;

bool decayed(double p);

int main() {
  int atoms = 10000;
  std::cout << "There are " << atoms << "atoms initially." << std::endl;
  int year = 1;
  while (true) {
    int newAtoms = 0;
    for (int i = 0; i < atoms; i++) {
      if (!decayed(decayP)) newAtoms++;
    }
    atoms = newAtoms;
    std::cout << "There are " << atoms << " atoms at the end of year " << year
              << std::endl;
    if (atoms == 0) break;
    year++;
  }
  return 0;
}

bool decayed(double p) { return (rand() / (double(RAND_MAX) + 1)) < p; }