#include <iostream>
using namespace std;

int MAX_SIZE = 100; // Maximum size of the array (can be changed by the user)

int insertAtBeginning(int arr[], int& size, int element) {
    if (size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert element." << endl;
        return size;
    }

    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = element;
    size++;

    return size;
}

int deleteFromBeginning(int arr[], int& size) {
    if (size <= 0) {
        cout << "Array is empty. Cannot delete element." << endl;
        return size;
    }

    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;

    return size;
}

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    int arr[MAX_SIZE];
    int size = 0;

    cout << "Enter the size of the array (up to " << MAX_SIZE << "): ";
    cin >> size;

    if (size > MAX_SIZE || size <= 0) {
        cout << "Invalid size. Exiting program." << endl;
        return 0;
    }

    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int element;

    cout << "Enter element to insert at the beginning: ";
    cin >> element;

    size = insertAtBeginning(arr, size, element);

    cout << "Updated array after insertion:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    size = deleteFromBeginning(arr, size);

    cout << "Updated array after deletion:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}