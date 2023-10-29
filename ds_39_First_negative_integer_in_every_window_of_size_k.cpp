#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> findFirstNegative(int arr[], int n, int k) {
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

    for (int i = k; i < n; i++) {
        if (!dq.empty()) {
            result.push_back(arr[dq.front()]);
        } else {
            result.push_back(0);
        }

        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

    if (!dq.empty()) {
        result.push_back(arr[dq.front()]);
    } else {
        result.push_back(0);
    }

    return result;
}

int main() {
    cout<<"Himank Kumar C0/206"<<endl;
    int arr[] = {-8, 2, 3, -6, 10,9,-4,4,-34};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout<<"Original Array: ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    vector<int> result = findFirstNegative(arr, n, k);

    cout << "First negative integer in every window of size " << k << ":\n";
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}