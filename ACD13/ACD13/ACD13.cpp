#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

const size_t TABLE_SIZE = 30;

unsigned int hashFunction(const std::string& str) {
    unsigned int hash = 0;
    for (char ch : str) {
        hash = (hash * 31 + ch) % TABLE_SIZE;
    }
    return hash;
}

struct HashEntry {
    std::string key; // Слово
    std::string value; // Значение для слова с номером
};

int main() {
    setlocale(LC_ALL, "");
    std::string inputFileName, outputFileName;

    std::cout << "Введите имя входного файла: ";
    std::cin >> inputFileName;
    std::cout << "Введите имя выходного файла: ";
    std::cin >> outputFileName;

    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    std::vector<HashEntry> hashTable(TABLE_SIZE);
    std::set<std::string> addedWords; // множество для отслеживания добавленных слов
    int counter = 1; // Начинаем с 1

    std::string word;

    while (inputFile >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Проверяем, есть ли слово уже в множестве
        if (addedWords.count(word)) continue;


        unsigned int index = hashFunction(word);
        bool inserted = false;

        for (size_t i = 0; i < TABLE_SIZE; ++i) {
            size_t newIndex = (index + i) % TABLE_SIZE;
            if (hashTable[newIndex].key.empty()) {
                hashTable[newIndex].key = word;
                hashTable[newIndex].value = std::to_string(counter) + "-" + word;
                counter++;
                inserted = true;
                addedWords.insert(word); // Добавляем слово в множество после успешной вставки
                break;
            }
            //Если ячейка занята другим словом, то мы пропускаем её.
        }

        if (!inserted) {
            std::cerr << "Не удалось вставить слово: " << word << ", таблица переполнена!" << std::endl;
        }
    }

    inputFile.close();

    outputFile << "Хеш-таблица (размер: " << TABLE_SIZE << "):" << std::endl;
    for (size_t i = 0; i < TABLE_SIZE; ++i) {
        if (!hashTable[i].key.empty()) {
            outputFile << i << ": " << hashTable[i].key << std::endl;
        }
    }

    outputFile.close();
    std::cout << "Хеш-таблица успешно записана в файл " << outputFileName << std::endl;

    return 0;
}
