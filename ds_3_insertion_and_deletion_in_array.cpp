#include <iostream>
using namespace std;

int MAX_SIZE = 100; // Maximum size of the array (can be changed by the user)

int insertElement(int arr[], int& size, int position, int element) {
    if (size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert element." << endl;
        return size;
    }

    if (position < 0 || position > size) {
        cout << "Invalid position. Cannot insert element." << endl;
        return size;
    }

    for (int i = size; i >= position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = element;
    size++;

    return size;
}

int deleteElement(int arr[], int& size, int position) {
    if (size <= 0) {
        cout << "Array is empty. Cannot delete element." << endl;
        return size;
    }

    if (position < 0 || position >= size) {
        cout << "Invalid position. Cannot delete element." << endl;
        return size;
    }

    for (int i = position - 1; i < size - 1; i++) {
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

    cout<<"The Array so far is: "<<endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int position, element;
    
    cout << "Enter position to insert element: ";
    cin >> position;
    cout << "Enter element to insert: ";
    cin >> element;

    size = insertElement(arr, size, position, element);

    cout << "Updated array after insertion:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter position to delete element: ";
    cin >> position;

    size = deleteElement(arr, size, position);

    cout << "Updated array after deletion:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}