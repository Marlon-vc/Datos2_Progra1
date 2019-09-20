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
        CSVParser() {};
        CSVParser(std::string file, std::string delimiter);
        std::vector<std::vector<std::string>> getAllData();
        std::vector<std::string> getRowAt(int pos);
        std::vector<std::vector<std::string>> getRowsAt(int start, int end);
};

CSVParser::CSVParser(std::string file, std::string delimiter=",") {
    file_path = file;
    this->delimiter = delimiter;
}

std::vector<std::vector<std::string>> CSVParser::getAllData() {
    std::ifstream file(file_path); 
    std::vector<std::vector<std::string>> dataList;
    std::string line = "";
    while (getline(file, line)) {
        std::vector<std::string> vec;
        boost::algorithm::split(vec, line, boost::is_any_of(delimiter));
        dataList.push_back(vec);
    }
    file.close();
    return dataList;
}

int main() {
    std::cout << "starting..\n";
    CSVParser parser("/home/marlon/TEC/II Semestre 2019/Datos II/Datos2_Progra1/dataset/test.csv");
    std::vector<std::vector<std::string>> data = parser.getAllData();
    std::cout << data.size() << "\n";
    for (std::vector<std::string> vec:data) {
        for (std::string str:vec) {
            std::cout << str << " , ";
        }
        std::cout << "\n";
    }
    return 0;
}