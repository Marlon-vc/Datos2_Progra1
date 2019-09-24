#ifndef CSV_PARSER
#define CSV_PARSER

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <boost/algorithm/string.hpp>

class CSVParser {
    private:
        std::string file_path;
        std::string delimiter;
    public:
        CSVParser(std::string file, std::string delimiter);
        std::vector<std::vector<std::string>> getAllData();
        std::vector<std::string> getRowAt(int pos);
        std::vector<std::vector<std::string>> getRowsAt(int start, int end);
};

#endif