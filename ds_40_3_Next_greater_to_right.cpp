#include<iostream>
#include<stack>
using namespace std;
//Next greater to right

int main(){
    cout<<"Himank Kumar C0/206"<<endl;
    int arr[8] = {3,1,2,5,4,6,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ngr[n] = {0};
    ngr[n-1] = -1;

    cout<<"Original Array is: ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    stack<int> st;
    st.push(arr[n-1]);
    for (int i = n-2; i >= 0; i--){
        while (st.size() > 0 && st.top() <= arr[i]){
            st.pop();
        }
        if(st.size() == 0) ngr[i] = -1;
        else ngr[i] = st.top();

        st.push(arr[i]);
    }
    
    cout<<"Array of next greater to right is: ";
    for (int i = 0; i < n; i++){
        cout<<ngr[i]<<" ";
    }cout<<endl;

    return 0;
}