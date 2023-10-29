#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    int arr[100];
    int n;
    int element;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    if (n > 100) {
        cout << "Array size exceeds the limit of 100. Please enter a smaller size." << endl;
        return 1; // Exit with an error code
    }
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1) {
        cout << "Element not found in the array." << endl;
    } else {
        cout << "Element found at POSITION " << result+1 << " in the array." << endl;
    }
    return 0;
}