//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> shell_sort(vector<int> numbers) {
//    int n = numbers.size();
//    int gap = n / 2;
//    while (gap > 0) {
//        for (int i = gap; i < n; ++i) {
//            int temp = numbers[i];
//            int j = i;
//            while (j >= gap && numbers[j - gap] > temp) {
//                numbers[j] = numbers[j - gap];
//                j -= gap;
//            }
//            numbers[j] = temp;
//        }
//        gap /= 2;
//    }
//    return numbers;
//}
//
//int main() {
//    setlocale(LC_ALL, "");
//    vector<int> numbers = { 5, 1, 4, 2, 8, 7, 3 }; 
//    vector<int> sorted_numbers = shell_sort(numbers);
//    cout << "Отсортированный список: ";
//    for (int number : sorted_numbers) {
//        cout << number << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
