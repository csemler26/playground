#include <iostream>
#include "csvParser.h"

bool testFromFile() 
{
  tools::CsvParser parser;

  if (!parser.loadFromFile("example_1.csv")) {
    std::cout << "Error opening file" << std::endl;
  }

  parser.print();

  auto row = parser.getRow(0);
  std::cout << "First field in the first row: " << parser.getField(0,0) << std::endl;

  return true;
}

bool testFromString()
{
  return true;
}

bool testStdIn()
{
  tools::CsvParser parser;

  parser.loadFromStdin();

  parser.print();
  
  return true;
}

int main() {
  std::cout << "Testing CSV Parser" << std::endl;

  testFromFile();
  testFromString();
  testStdIn();

  std::cout << "Test passed!" << std::endl;
  return 0;
}