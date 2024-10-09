#ifndef TOOLS_CSV_PARSER_H
#define TOOLS_CSV_PARSER_H

#include <string>
#include <vector>

namespace tools {

class CsvParser {
public:
  CsvParser(char delimiter = ',', char quoteChar = '"');
  ~CsvParser();

  bool loadFromFile(const std::string& filePath);
  bool loadFromString(const std::string& data);
  std::vector<std::string> getRow(size_t rowIndex) const;
  std::string getField(size_t row, size_t col) const;
  size_t rowCount() const;
  size_t colCount() const;
  void print() const;

private:
  std::vector<std::string> parseLine(const std::string& line);
  std::string trim(const std::string& field);

  char delimiter_;
  char quoteChar_;
  std::vector<std::vector<std::string>> data_;
};

} // namespace tools

#endif // TOOLS_CSV_PARSER_H