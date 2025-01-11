#include <iostream>
#include <string>

void calcEaster(int year, std::string &month, std::string &day);
void calcEasterGauss(int year, std::string &month, std::string &day);
void printEaster(int year, std::string month, std::string day);
void error(std::string);

int main() {
  std::string month, day;

  std::cout << "Using Gauss algorithm:" << std::endl;
  calcEasterGauss(1700, month, day);
  printEaster(1700, month, day);  // Expected: April 11th
  calcEasterGauss(1800, month, day);
  printEaster(1800, month, day);  // Expected: April 13th

  std::cout << "Using generalized algorithm:" << std::endl;
  calcEaster(2000, month, day);
  printEaster(2000, month, day);  // Expected: April 23rd
  calcEaster(2025, month, day);
  printEaster(2025, month, day);  // Expected: April 20th

  return 0;
}

void calcEaster(int year, std::string &month, std::string &day) {
  int a = year % 19;
  int b = year / 100;
  int c = year % 100;
  int d = b / 4;
  int e = b % 4;
  int f = (b + 8) / 25;
  int g = (b - f + 1) / 3;
  int h = (19 * a + b - d - g + 15) % 30;
  int i = c / 4;
  int k = c % 4;
  int l = (32 + 2 * e + 2 * i - h - k) % 7;
  int m = (a + 11 * h + 22 * l) / 451;
  month = ((h + l - 7 * m + 114) / 31) == 3 ? "March" : "April";
  int p = (h + l - 7 * m + 114) % 31;
  day = std::to_string(p + 1);
}

void calcEasterGauss(int year, std::string &month, std::string &day) {
  // I
  int a = year % 19;
  int b = year % 4;
  int c = year % 7;

  // II
  int d = ((19 * a) + 23) % 30;

  // III
  int e;
  if (year >= 1700 && year <= 1799) {
    e = ((2 * b) + (4 * c) + (6 * d) + 3) % 7;
  } else if (year >= 1800 && year <= 1899) {
    e = ((2 * b) + (4 * c) + (6 * d) + 4) % 7;
  } else {
    throw std::invalid_argument(
        "Invalid year, must be between 1700 and 1899: " + std::to_string(year));
  }

  // Calculate
  if (d + e <= 9) {
    month = "March";
    day = std::to_string(22 + d + e);
  } else {
    month = "April";
    day = std::to_string(d + e - 9);
  }
}

void printEaster(int year, std::string month, std::string day) {
  std::cout << year << " Easter: " << month << ", " << day << std::endl;
}

void error(std::string msg) {
  std::cerr << msg << std::endl;
  exit(EXIT_FAILURE);
}