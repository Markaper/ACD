//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> sort_by_selection(vector<int> numbers) {
//    int n = numbers.size();
//    for (int i = 0; i < n - 1; ++i) {
//        int min_idx = i;
//        for (int j = i + 1; j < n; ++j) {
//            if (numbers[j] < numbers[min_idx]) {
//                min_idx = j;
//            }
//        }
//        swap(numbers[i], numbers[min_idx]);
//    }
//    return numbers;
//}
//
//int main() {
//    setlocale(LC_ALL, "");
//    vector<int> numbers = { 64, 34, 25, 12, 22, 11, 90 };
//    vector<int> sorted_numbers = sort_by_selection(numbers);
//    cout << "Отсортированный список: ";
//    for (int number : sorted_numbers) {
//        cout << number << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
