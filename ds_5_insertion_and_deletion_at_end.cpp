#include <iostream>
using namespace std;

int MAX_SIZE = 100; // Maximum size of the array (can be changed by the user)

void insertElement(int arr[], int& size, int element) {
    if (size >= MAX_SIZE) {
        cout << "Overflow! Array is full. Cannot insert element." << endl;
        return;
    }

    arr[size] = element;
    size++;

    cout << "Element inserted at the end successfully." << endl;
}

void deleteElement(int arr[], int& size) {
    if (size <= 0) {
        cout << "Underflow! Array is empty. Cannot delete element." << endl;
        return;
    }

    size--;

    cout << "Element deleted from the end successfully." << endl;
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

    cout << "Enter element to insert at the end: ";
    cin >> element;

    insertElement(arr, size, element);

    cout << "Updated array after insertion:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    deleteElement(arr, size);

    cout << "Updated array after deletion:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}