#include <iostream>
using namespace std;

int findFloor(int arr[], int size, int target) {
    int floor = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] <= target) {
            floor = arr[i];
        } else {
            break;
        }
    }

    return floor;
}

int findCeil(int arr[], int size, int target) {
    int ceil = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] >= target) {
            ceil = arr[i];
            break;
        }
    }

    return ceil;
}

int findPeak(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if ((i == 0 || arr[i] >= arr[i - 1]) && (i == size - 1 || arr[i] >= arr[i + 1])) {
            return arr[i];
        }
    }

    return -1;
}

int findMinimum(int arr[], int size) {
    int minimum = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    return minimum;
}

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    int arr[6] = {8, 9, 10, 2, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter target value: ";
    cin >> target;

    int floor = findFloor(arr, size, target);
    int ceil = findCeil(arr, size, target);
    int peak = findPeak(arr, size);
    int minimum = findMinimum(arr, size);

    cout << "Floor: " << floor << endl;
    cout << "Ceil: " << ceil << endl;
    cout << "Peak: " << peak << endl;
    cout << "Minimum: " << minimum << endl;

    return 0;
}
