#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

std::string simpleHash(const std::string& str) {
    std::hash<std::string> hashFn;
    return std::to_string(hashFn(str));
}

void createHashTable(const std::string& inputFile, std::unordered_map<std::string, std::vector<std::string>>& hashTable) {
    std::ifstream file(inputFile);
    std::string line;

    while (std::getline(file, line)) {
        if (!line.empty()) {
            std::string hashed = simpleHash(line);
            hashTable[hashed].push_back(line);
        }
    }
}

void writeHashTableToFile(const std::unordered_map<std::string, std::vector<std::string>>& hashTable, const std::string& outputFile) {
    std::ofstream file(outputFile);
    for (const auto& pair : hashTable) {
        file << pair.first << ": ";
        for (const auto& value : pair.second) {
            file << value << ", ";
        }
        file << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::string inputFilename = "input.txt";  
    std::string outputFilename = "output.txt";  

    std::unordered_map<std::string, std::vector<std::string>> hashTable;
    createHashTable(inputFilename, hashTable);
    writeHashTableToFile(hashTable, outputFilename);

    std::cout << "Хеш-таблица успешно создана и записана в файл " << outputFilename << std::endl;

    return 0;
}
