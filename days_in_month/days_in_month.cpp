#include <format>
#include <iostream>
#include <magic_enum.hpp>
#include <string>

#include "titleize.h"

enum class Month {
  JANUARY = 1,
  FEBRUARY,
  MARCH,
  APRIL,
  MAY,
  JUNE,
  JULY,
  AUGUST,
  SEPTEMBER,
  OCTOBER,
  NOVEMBER,
  DECEMBER
};

int daysInMonth(Month month, int year);
Month intToMonth(int monthNumber);
bool isLeapYear(int year);

int main() {
  int monthNumber, year;

  std::cout << "Please enter a month number: ";
  std::cin >> monthNumber;

  std::cout << "Please enter a year: ";
  std::cin >> year;

  try {
    Month month = intToMonth(monthNumber);
    int monthDays = daysInMonth(month, year);
    std::string monthName = std::string(magic_enum::enum_name(month));
    std::string monthTitlized = cpp_abstractions::titleize::titleize(monthName);
    std::cout << std::format("Month {} has {} days in year {}.", monthTitlized,
                             monthDays, year)
              << std::endl;
    return 0;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
}

Month intToMonth(int monthNumber) {
  auto month = magic_enum::enum_cast<Month>(monthNumber);
  if (month.has_value()) return month.value();
  throw std::invalid_argument("Invalid month number: " +
                              std::to_string(monthNumber));
}

int daysInMonth(Month month, int year) {
  switch (month) {
    case Month::APRIL:
    case Month::JUNE:
    case Month::SEPTEMBER:
    case Month::NOVEMBER:
      return 30;
    case Month::FEBRUARY:
      return (isLeapYear(year)) ? 29 : 28;
    default:
      return 31;
  }
}

bool isLeapYear(int year) {
  return (year % 4 == 0) && (!(year % 100 == 0) || (year % 400 == 0));
}