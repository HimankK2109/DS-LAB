#include <iostream>
using namespace std;

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    int arr[100];
    int size;

    cout << "Enter the size of the array (up to 100): ";
    cin >> size;

    if (size > 100 || size <= 0) {
        cout << "Invalid size. Exiting program." << endl;
        return 0;
    }

    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Bubble Sort Algorithm
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
