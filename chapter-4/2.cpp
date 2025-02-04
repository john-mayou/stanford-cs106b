#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

const int cellWidth = 5;
const int tMin = -45;
const int tMax = 40;
const int vMin = 5;
const int vMax = 60;

double windChill(int t, int v);
int roundNum(double);
void error(std::string);
void printCell(std::string);
void printEndl();

int main() {
  // print x axis labels
  printCell("Calm");
  for (int i = tMax; i >= tMin; i -= 5) {
    printCell(std::to_string(i));
  }
  printEndl();

  // print table
  for (int v = vMin; v <= vMax; v += 5) {
    printCell(std::to_string(v));  // print y axis label
    for (int t = tMax; t >= tMin; t -= 5) {
      printCell(std::to_string(roundNum(windChill(t, v))));
    }
    printEndl();
  }

  return 0;
}

double windChill(int t, int v) {
  if (v == 0) return t;
  if (t > 40) error("temp is greater than 40, exiting.");
  return 35.74 + (0.6215 * t) - (35.75 * std::pow(v, 0.16)) +
         (0.4275 * t * std::pow(v, 0.16));
}

int roundNum(double n) { return (n > 0) ? int(n + 0.5) : int(n - 0.5); }

void error(std::string msg) {
  std::cerr << msg << std::endl;
  exit(EXIT_FAILURE);
}

void printCell(std::string text) {
  std::cout << std::setw(cellWidth) << std::left << text;
}

void printEndl() { std::cout << std::endl; }