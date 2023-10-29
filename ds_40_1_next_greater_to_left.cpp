#include<iostream>
#include<stack>
using namespace std;
//next greater to left

int main(){
    cout<<"Himank Kumar C0/206"<<endl;
    int arr[8] = {3,1,2,5,4,6,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int pge[n] = {0};
    pge[0] = -1;

    cout<<"Original Array is: ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    stack<int> st;
    st.push(arr[0]);
    for (int i = 1; i < n; i++){
        while (st.size() > 0 && st.top() <= arr[i]){
            st.pop();
        }
        if(st.size() == 0) pge[i] = -1;
        else pge[i] = st.top();

        st.push(arr[i]);
    }
    
    cout<<"Array of next greater to left is: ";
    for (int i = 0; i < n; i++){
        cout<<pge[i]<<" ";
    }cout<<endl;

    
    return 0;
}