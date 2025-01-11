#include "calendar.h"

int daysInMonth(int year, Month month) {
  switch (month) {
    case Month::APRIL:
    case Month::JUNE:
    case Month::SEPTEMBER:
    case Month::NOVEMBER:
      return 30;
    case Month::FEBRUARY:
      return isLeapYear(year) ? 29 : 28;
    default:
      return 31;
  }
}

bool isLeapYear(int year) {
  return (year % 4 == 0) && (!(year % 100 == 0) || (year % 400 == 0));
}