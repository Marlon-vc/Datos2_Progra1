#include "csv_parser.hpp"

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

std::vector<std::string> CSVParser::getRowAt(int pos) {
    std::ifstream file(file_path);
    std::vector<std::string> row;
    std::string line = "";
    int c = 1;
    while (c <= pos) {
        getline(file, line);
        c++;
    }
    file.close();
    boost::algorithm::split(row, line, boost::is_any_of(delimiter));
    return row;
}

std::vector<std::vector<std::string>> CSVParser::getRowsAt(int start, int end) {
    std::ifstream file(file_path); 
    std::vector<std::vector<std::string>> range;
    std::string line = "";

    int c = 1;
    while (c <= end) {
        getline(file, line);

        if (c >= start && c <=end) {
            std::vector<std::string> vec;
            boost::algorithm::split(vec, line, boost::is_any_of(delimiter));
            range.push_back(vec);
        }
        c++;
    }
    file.close();
    return range;
}

int main() {
    std::cout << "starting..\n";
    CSVParser parser("/home/marlon/TEC/II Semestre 2019/Datos II/Datos2_Progra1/dataset/test.csv");
    std::vector<std::vector<std::string>> data = parser.getRowsAt(4, 6);
    
    for (std::vector<std::string> vec : data) {
        for (std::string item : vec) {
            std::cout << item << ", ";
        }
        std::cout << "\n";
    }

    std::cout << "Specific row\n";
    std::vector<std::string> row = parser.getRowAt(2);
    
    for (std::string item: row) {
        std::cout << item << ", ";
    }
    std::cout << "\n";

    return 0;
}