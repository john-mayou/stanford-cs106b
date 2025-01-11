#include <cctype>
#include <iomanip>
#include <iostream>
#include <magic_enum/magic_enum.hpp>

#include "calendar.h"

const int streamWidth = 9;

void printDays(int year, Month month);
std::string titleize(std::string str);

int main() {
  int year;
  std::cout << "Please enter a year: ";
  std::cin >> year;

  printDays(year, Month::JANUARY);
  printDays(year, Month::FEBRUARY);
  printDays(year, Month::MARCH);
  printDays(year, Month::APRIL);
  printDays(year, Month::MAY);
  printDays(year, Month::JUNE);
  printDays(year, Month::JULY);
  printDays(year, Month::AUGUST);
  printDays(year, Month::SEPTEMBER);
  printDays(year, Month::OCTOBER);
  printDays(year, Month::NOVEMBER);
  printDays(year, Month::DECEMBER);

  return 0;
}

void printDays(int year, Month month) {
  std::cout << std::setw(streamWidth)
            << titleize(std::string(magic_enum::enum_name(month))) << " has "
            << daysInMonth(year, month) << " days" << std::endl;
}

std::string titleize(std::string input) {
  std::string str = "";
  bool titleizeNext = true;

  for (int i = 0; i < input.length(); i++) {
    char ch = input[i];
    if (std::isspace(ch)) {
      str += ch;
      titleizeNext = true;
    } else if (titleizeNext) {
      str += std::toupper(ch);
      titleizeNext = false;
    } else {
      str += std::tolower(ch);
    }
  }

  return str;
}