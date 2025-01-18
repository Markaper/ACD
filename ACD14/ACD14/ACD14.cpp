#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <sstream>

const int TABLE_SIZE = 10; // Размер хеш-таблицы

class HashTable {
private:
    std::vector<std::list<std::string>> table;

    // Хеш-функция
    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char ch : key) {
            hash += static_cast<int>(ch);
        }
        return hash % TABLE_SIZE; // Остаток от деления
    }

public:
    HashTable() : table(TABLE_SIZE) {}

    // Метод для вставки слова в хеш-таблицу
    void insert(const std::string& key) {
        int index = hashFunction(key);
        table[index].push_back(key); // Вставляем ключ в соответствующий список
    }

    // Метод для записи содержимого хеш-таблицы в файл
    void writeToFile(std::ofstream& outfile) {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (!table[i].empty()) {
                outfile << i << ": "; // Индекс хеш-таблицы
                for (const std::string& str : table[i]) {
                    outfile << str << " "; // Записываем ключи
                }
                outfile << std::endl;
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "");
    HashTable hashTable;

    std::ifstream infile("input.txt");
    if (!infile.is_open()) {
        std::cerr << "Ошибка при открытии файла input.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) { // Чтение строк из файла
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) { // Чтение слов из строки
            hashTable.insert(word); // Вставка слова в хеш-таблицу
        }
    }

    infile.close(); // Закрыть входной файл

    std::ofstream outfile("output.txt");
    if (!outfile.is_open()) {
        std::cerr << "Ошибка при создании файла output.txt" << std::endl;
        return 1;
    }

    hashTable.writeToFile(outfile); // Запись содержимого хеш-таблицы в файл

    outfile.close(); // Закрыть выходной файл

    std::cout << "Работа завершена, данные записаны в output.txt." << std::endl;

    return 0;
}