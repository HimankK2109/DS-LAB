#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  
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
     if(n>100){
        cout<<"OVERFLOW-you cannot add more elements to array"<<endl;
    }
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    int result = linearSearch(arr, n, key);
    switch (result) {
        case -1:
            cout << "Element not found in the array." << endl;
            break;
        default:
            cout << "Element found at position " << result+1 << " in the array." << endl;
            break;
    }
    return 0;
}