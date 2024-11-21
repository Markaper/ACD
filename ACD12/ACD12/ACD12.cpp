#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

void mergeFiles(const std::vector<std::string>& tempFiles, const std::string& outputFile) {
    std::vector<std::ifstream> fileStreams(tempFiles.size());
    std::vector<int> currentValues(tempFiles.size());
    std::vector<bool> hasValue(tempFiles.size(), false);

    for (size_t i = 0; i < tempFiles.size(); ++i) {
        fileStreams[i].open(tempFiles[i]);
        if (fileStreams[i] >> currentValues[i]) {
            hasValue[i] = true;
        }
    }

    std::ofstream outFile(outputFile);
    while (true) {
        int minIndex = -1;
        for (size_t i = 0; i < hasValue.size(); ++i) {
            if (hasValue[i] && (minIndex == -1 || currentValues[i] < currentValues[minIndex])) {
                minIndex = i;
            }
        }
        if (minIndex == -1) {
            break;
        }
        outFile << currentValues[minIndex] << "\n";
        if (fileStreams[minIndex] >> currentValues[minIndex]) {
            continue;
        }
        hasValue[minIndex] = false;
    }
}

void sortTempFile(const std::string& tempFile, int numbersPerFile) {
    std::ifstream inFile(tempFile);
    std::vector<int> numbers;
    int number;

    while (inFile >> number) {
        numbers.push_back(number);
    }
    std::sort(numbers.begin(), numbers.end());
    std::ofstream outFile(tempFile);

    for (int num : numbers) {
        outFile << num << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "");
    std::ifstream inputFile("input.txt");
    std::vector<int> numbers;
    int number;

    while (inputFile >> number) {
        numbers.push_back(number);
    }

    int numbersPerFile = 8;
    int totalFiles = (numbers.size() + numbersPerFile - 1) / numbersPerFile;
    std::vector<std::string> tempFiles(totalFiles);

    for (int i = 0; i < totalFiles; ++i) {
        tempFiles[i] = "temp" + std::to_string(i) + ".txt";
        std::ofstream tempFile(tempFiles[i]);
        for (int j = 0; j < numbersPerFile && (i * numbersPerFile + j) < numbers.size(); ++j) {
            tempFile << numbers[i * numbersPerFile + j] << "\n";
        }
    }

    for (const auto& tempFile : tempFiles) {
        sortTempFile(tempFile, numbersPerFile);
    }

    mergeFiles(tempFiles, "output.txt");

    return 0;
}
