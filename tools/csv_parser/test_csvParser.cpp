#include <iostream>
#include "csvParser.h"

int main() {
  std::cout << "Testing CSV Parser" << std::endl;

  tools::CsvParser parser;

  if (!parser.loadFromFile("example_1.csv")) {
    std::cout << "Error opening file" << std::endl;
  }

  parser.print();

  auto row = parser.getRow(0);
  std::cout << "First field in the first row: " << parser.getField(0,0) << std::endl;

  return 0;
}