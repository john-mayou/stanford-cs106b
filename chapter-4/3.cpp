#include <cassert>
#include <cerrno>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

const std::string TESTFILE =
    std::filesystem::path(__FILE__).parent_path() / "test.text";

int main() {
  // write a file
  std::ofstream ofile(TESTFILE);
  if (!ofile) {
    std::cerr << "Error: could not open file: " << TESTFILE;
    return 1;
  }
  ofile << "This is not the longest line 1" << std::endl;
  ofile << "This is not the longest line 2" << std::endl;
  ofile << "This is absolutely the longest line in this file" << std::endl;
  ofile << "This is not the longest line 4" << std::endl;
  ofile << "This is not the longest line 5" << std::endl;
  ofile.close();

  // find the longest line
  std::ifstream ifile(TESTFILE);
  if (!ifile) {
    std::cerr << "Error: could not open file: " << strerror(errno);
    return 1;
  }

  int longestLen = 0;
  std::string longest = "";
  std::string line;
  while (std::getline(ifile, line)) {
    int lineLen = line.length();
    if (lineLen > longestLen) {
      longestLen = lineLen;
      longest = line;
    }
  }

  if (ifile.fail() && !ifile.eof()) {
    std::cerr << "Error: error reading file: " << strerror(errno);
    return 1;
  }

  ifile.close();
  std::remove(TESTFILE.c_str());
  if (std::filesystem::exists(TESTFILE)) {
    std::cerr << "Error: file was not deleted successfully: "
              << strerror(errno);
    return 1;
  }

  assert(longest == "This is absolutely the longest line in this file");

  return 0;
}