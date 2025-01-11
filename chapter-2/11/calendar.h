#ifndef _calendar_h
#define _calendar_h

enum class Month {
  JANUARY,
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
  DECEMBER,
};

int daysInMonth(int year, Month month);

bool isLeapYear(int year);

#endif