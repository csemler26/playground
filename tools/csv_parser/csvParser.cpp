#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "csvParser.h"

namespace tools {

CsvParser::CsvParser(char delimiter, char quoteChar)
  : delimiter_(delimiter),
    quoteChar_(quoteChar)
{
};

CsvParser::~CsvParser()
{
};

bool CsvParser::loadFromFile(const std::string& filePath) {
  std::ifstream file(filePath);
  
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filePath << std::endl;
    return false;
  }

  std::string line;
  while (std::getline(file, line)) {
    data_.push_back(parseLine(line));
  }

  file.close();
  return true;
}

bool CsvParser::loadFromString(const std::string& data) {
  std::istringstream stream(data);
  std::string line;
  while (std::getline(stream, line)) {
    data_.push_back(parseLine(line));
  }
  return true;
}

std::vector<std::string> CsvParser::getRow(size_t row) const {
  if (row >= data_.size()) {
    return std::vector<std::string>();
  }
  return data_[row];
}

std::string CsvParser::getField(size_t row, size_t col) const {
  if (row >= data_.size() || col >= data_[row].size()) {
    return "";
  }
  return data_[row][col];
}

size_t CsvParser::rowCount() const {
  return data_.size();
}

size_t CsvParser::colCount() const {
  return data_.empty() ? 0 : data_[0].size();
}

void CsvParser::print() const {
  for (const auto& row : data_) {
    std::cout << " | ";
    for (const auto& field : row) {
      std::cout << field << " | ";
    }
    std::cout << std::endl;
  }
}

std::vector<std::string> CsvParser::parseLine(const std::string& line) {
  std::vector<std::string> result;
  std::string field;
  bool inQuotes = false;

  for (char ch : line) {
    if (ch == quoteChar_) {
      inQuotes = !inQuotes;
    } else if (ch == delimiter_ && !inQuotes) {
      result.push_back(trim(field));
      field.clear();
    } else {
      field += ch;
    }
  }
  result.push_back(trim(field));
  return result;
}

std::string CsvParser::trim(const std::string& field) {
  size_t first = field.find_first_not_of(' ');
  size_t last = field.find_last_not_of(' ');
  return (first == std::string::npos || last == std::string::npos) ? "" : field.substr(first, last - first + 1);
}

} // namespace tools