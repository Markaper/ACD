//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void radix_sort(vector<int>& numbers, int radix, int exp) {
//    int n = numbers.size();
//    vector<int> output(n);
//    vector<int> count(radix, 0);
//    for (int i = 0; i < n; ++i) {
//        count[(numbers[i] / exp) % radix]++;
//    }
//    for (int i = 1; i < radix; ++i) {
//        count[i] += count[i - 1];
//    }
//    for (int i = n - 1; i >= 0; --i) {
//        output[count[(numbers[i] / exp) % radix] - 1] = numbers[i];
//        count[(numbers[i] / exp) % radix]--;
//    }
//    for (int i = 0; i < n; ++i) {
//        numbers[i] = output[i];
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "");
//    vector<int> numbers = { 170, 45, 75, 90, 802, 24, 2, 66 };
//    int max = numbers[0];
//    for (int i = 1; i < numbers.size(); ++i) {
//        if (numbers[i] > max) {
//            max = numbers[i];
//        }
//    }
//    for (int exp = 1; max / exp > 0; exp *= 10) {
//        radix_sort(numbers, 10, exp);
//    }
//    cout << "Отсортированный список: ";
//    for (int number : numbers) {
//        cout << number << " ";
//    }
//    cout << endl;
//    return 0;
//}
