#include <cassert>
#include <cerrno>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

const std::string TESTFILE =
    std::filesystem::path(__FILE__).parent_path() / "test.txt";

int main() {
  // write file
  std::ofstream ofile(TESTFILE);
  if (!ofile) {
    std::cerr << "Error: could not open file: " << strerror(errno) << std::endl;
    return 1;
  }

  ofile << "line 1" << std::endl;
  ofile << "line 2" << std::endl;
  ofile << "line 3" << std::endl;
  ofile << "line 4" << std::endl;
  ofile << "line 5" << std::endl;

  ofile.close();

  // find lines and words
  std::ifstream ifile(TESTFILE);
  if (!ifile) {
    std::cerr << "Error: could not open file: " << strerror(errno) << std::endl;
    return 1;
  }

  int lines;
  int words;
  std::string line;
  while (std::getline(ifile, line)) {
    lines++;
    bool isword = false;
    int lineLen = line.length();
    for (int i = 0; i < lineLen; i++) {
      char ch = line[i];
      if (ch == ' ') {
        if (isword) {
          words++;
          isword = false;
        }
      } else {
        isword = true;
      }
    }
    if (isword) {
      words++;
    }
  }

  ifile.close();

  // cleanup
  std::remove(TESTFILE.c_str());
  if (std::filesystem::exists(TESTFILE)) {
    std::cerr << "Error: could not remove file: " << strerror(errno)
              << std::endl;
    return 1;
  }

  // test
  assert(lines == 5);
  assert(words == 10);

  return 0;
}