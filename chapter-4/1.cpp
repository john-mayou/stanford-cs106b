#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

void writeHeader(std::ostream &out);
void writeSeparator(std::ostream &out);
void writeRow(std::ostream &out, float theta, float sin, float cos);
void writeCenteredText(std::ostream &out, std::string str, int width);

const std::string thetaColHeader = "theta";
const std::string sinColHeader = "sin(theta)";
const std::string cosColHeader = "cos(theta)";

const int whiteSpaceWidth = 2;
const int thetaColWidth = thetaColHeader.length() + whiteSpaceWidth;
const int sinColWidth = sinColHeader.length() + whiteSpaceWidth;
const int cosColWidth = cosColHeader.length() + whiteSpaceWidth;

int main() {
  writeHeader(std::cout);
  writeSeparator(std::cout);
  for (int t = -90; t <= 90; t += 15) {
    writeRow(std::cout, t, std::sin(t), std::cos(t));
  }

  return 0;
}

void writeHeader(std::ostream &out) {
  out << '|';
  writeCenteredText(out, thetaColHeader, thetaColWidth);
  out << '|';
  writeCenteredText(out, sinColHeader, sinColWidth);
  out << '|';
  writeCenteredText(out, cosColHeader, cosColWidth);
  out << '|' << std::endl;
}

void writeSeparator(std::ostream &out) {
  out << '+';
  writeCenteredText(out, std::string(thetaColWidth, '-'), thetaColWidth);
  out << '+';
  writeCenteredText(out, std::string(sinColWidth, '-'), sinColWidth);
  out << '+';
  writeCenteredText(out, std::string(cosColWidth, '-'), cosColWidth);
  out << '+' << std::endl;
}

void writeRow(std::ostream &out, float theta, float sin, float cos) {
  out << '|';

  std::ostringstream oss;

  oss << theta;
  writeCenteredText(out, oss.str(), thetaColWidth);
  out << '|';
  oss.str("");

  oss << std::setprecision(7) << sin;
  writeCenteredText(out, oss.str(), sinColWidth);
  out << '|';
  oss.str("");

  oss << std::setprecision(7) << cos;
  writeCenteredText(out, oss.str(), cosColWidth);
  out << '|';
  oss.str("");

  out << std::endl;
}

void writeCenteredText(std::ostream &out, std::string str, int width) {
  int strLen = str.length();
  if (strLen > width) {
    throw std::invalid_argument(
        "length of the string is larger than the width for " + str + ":" +
        std::to_string(strLen) + " > " + std::to_string(width));
  } else if (strLen < width) {
    int padLeft = width - strLen;
    if (padLeft % 2 == 0) {
      std::string pad = std::string(padLeft / 2, ' ');
      out << pad << str << pad;
    } else {
      int smallPadLen = std::floor(padLeft / 2);
      out << std::string(smallPadLen + 1, ' ') << str
          << std::string(smallPadLen, ' ');
    }
  } else {  // same
    out << str;
  }
}