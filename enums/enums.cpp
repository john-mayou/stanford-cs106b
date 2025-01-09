#include <iostream>
#include <string>

enum class Color { RED = 1, BLUE = 2, GREEN = 3 };

Color intToColor(int value) {
  switch (value) {
    case 1:
    case 2:
    case 3:
      return static_cast<Color>(value);
    default:
      throw std::invalid_argument("Invalid color to serialize: " +
                                  std::to_string(value));
  }
}

int main() {
  std::string input;
  std::cout << "Enter a integer to convert to a color: ";
  std::cin >> input;
  try {
    intToColor(std::stoi(input));
    std::cout << "Successfully serialized color." << std::endl;
    return 0;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
}