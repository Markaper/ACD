#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);
        int partitionIndex = i + 1;
        quickSort(arr, left, partitionIndex - 1);
        quickSort(arr, partitionIndex, right);
    }
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(0));
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Исходный массив: ";
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, 0, n - 1);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
