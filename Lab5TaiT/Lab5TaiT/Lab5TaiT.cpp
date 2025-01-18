#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// Определение грамматики в нормальной форме Хомского
unordered_map<string, vector<vector<string>>> grammar = {
    {"S", {{"F", "A"}}},
    {"F", {{ "+" }}},
    {"A", {{"T", "G"}}},
    {"T", {{"b"}}},
    {"G", {{"Y", "B", "Z"}}},
    {"Y", {{"a"}}},
    {"Z", {{"c"}}},
    {"B", {{"D", "E", "P"}}},
    {"D", {{"a"}}},
    {"E", {{"b"}}},
    {"P", {{"c"}}}
};

// Функция для проверки строки методом CYK
bool CYK(const string& input) {
    int n = input.size();
    vector<vector<set<string>>> table(n, vector<set<string>>(n));

    // Заполняем таблицу для единичных правил
    for (int i = 0; i < n; ++i) {
        for (const auto& [nonterminal, rules] : grammar) {
            for (const auto& rule : rules) {
                if (rule.size() == 1 && rule[0] == string(1, input[i])) {
                    table[i][i].insert(nonterminal);
                }
            }
        }
    }

    // CYK-алгоритм
    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            for (int k = i; k < j; ++k) {
                for (const auto& [nonterminal, rules] : grammar) {
                    for (const auto& rule : rules) {
                        if (rule.size() == 2) {
                            const string& B = rule[0], & C = rule[1];
                            if (table[i][k].count(B) && table[k + 1][j].count(C)) {
                                table[i][j].insert(nonterminal);
                            }
                        }
                    }
                }
            }
        }
    }

    // Проверяем, принадлежит ли строка языку
    return table[0][n - 1].count("S");
}

// Функция для вывода таблицы разбора
void printCYKTable(const vector<vector<set<string>>>& table) {
    int n = table.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i <= j) {
                cout << "{";
                for (const auto& symbol : table[i][j]) {
                    cout << symbol << " ";
                }
                cout << "} ";
            }
            else {
                cout << "     ";
            }
        }
        cout << endl;
    }
}

// Функция для проверки строки методом Эрли
bool Earley(const string& input, const vector<string>& grammarRules) {
    // Эрли-алгоритм не реализован в этом коде для краткости
    // Вместо этого можно использовать стороннюю библиотеку
    cout << "Earley parser not implemented yet.\n";
    return false;
}

// Сравнение с исходным языком L = {+baⁿbcⁿ | n > 1}
bool belongsToL(const string& input) {
    if (input[0] != '+') return false;
    size_t pos = 1;

    // Проверяем последовательность "b"
    if (input[pos] != 'b') return false;
    ++pos;

    // Считаем количество "a" и "b"
    int countA = 0, countB = 0, countC = 0;
    while (pos < input.size() && input[pos] == 'a') {
        ++countA;
        ++pos;
    }

    // Проверяем наличие "b"
    while (pos < input.size() && input[pos] == 'b') {
        ++countB;
        ++pos;
    }

    // Проверяем наличие "c"
    while (pos < input.size() && input[pos] == 'c') {
        ++countC;
        ++pos;
    }

    return countA > 1 && countA == countB && countB == countC;
}

int main() {
    vector<string> testStrings = {
        "+baabbcc",
        "+babc",
        "+baaaabbbbbccccc",
        "+baaabbccc"
    };

    for (const string& input : testStrings) {
        cout << "Testing string: " << input << endl;

        // CYK проверка
        bool cykResult = CYK(input);
        cout << "CYK result: " << (cykResult ? "Accepted" : "Rejected") << endl;

        // Сравнение с языком L
        bool languageCheck = belongsToL(input);
        cout << "Belongs to L: " << (languageCheck ? "Yes" : "No") << endl;

        cout << endl;
    }

    return 0;
}