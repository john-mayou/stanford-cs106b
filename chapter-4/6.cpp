#include <cassert>
#include <cerrno>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

std::string defaultExt(std::string filename, std::string ext);

int main() {
  assert(defaultExt("", "") == "");
  assert(defaultExt("", ".ext") == "");
  assert(defaultExt("file", "") == "file");
  assert(defaultExt("file", ".ext") == "file.ext");
  assert(defaultExt("file.ext", ".ext") == "file.ext");
  assert(defaultExt("file.ext", ".ext2") == "file.ext");
  assert(defaultExt("file.ext", "*.ext2") == "file.ext2");

  return 0;
}

std::string defaultExt(std::string filename, std::string ext) {
  if (ext == "" || filename == "") {
    return filename;
  }

  // no existing extension, just add it
  if (filename.find('.') == std::string::npos) {
    return filename + ext;
  }

  // no *, so we're not overring it
  if (ext.find('*') == std::string::npos) {
    return filename;
  }

  // now we can override it
  std::string basename = "";
  for (int i = 0; i < filename.length() - 1; i++) {
    char ch = filename[i];
    if (ch == '.') break;
    basename += ch;
  }

  return basename + ext.substr(1, std::string::npos);
}