#include <cassert>
#include <cerrno>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

std::string basename(std::string filename);
std::string extension(std::string filename);

int main() {
  // basename
  {
    assert(basename("") == "");
    assert(basename("file") == "file");
    assert(basename("file.rb") == "file");
    assert(basename("file.ext") == "file");
  }

  // extension
  {
    assert(extension("") == "");
    assert(extension("file") == "");
    assert(extension("file.rb") == ".rb");
    assert(extension("file.ext") == ".ext");
  }

  return 0;
}

std::string basename(std::string filename) {
  if (filename == "" || filename.find('.') == std::string::npos) {
    return filename;
  }

  std::string basename = "";
  for (int i = 0; i < filename.length(); i++) {
    char ch = filename[i];
    if (ch == '.') break;
    basename += ch;
  }

  return basename;
}

std::string extension(std::string filename) {
  if (filename == "" || filename.find('.') == std::string::npos) {
    return "";
  }

  std::string ext = "";
  for (int i = filename.length() - 1; i >= 0; i--) {
    char ch = filename[i];
    ext += ch;
    if (ch == '.') break;
  }

  // reverse in place
  int p1 = 0;
  int p2 = ext.length() - 1;
  while (true) {
    char tp = ext[p2];
    ext[p2] = ext[p1];
    ext[p1] = tp;

    p1++;
    p2--;

    if (p1 >= p2) break;
  }

  return ext;
}
