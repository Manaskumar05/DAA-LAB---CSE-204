#include <bits/stdc++.h>
using namespace std;

void bucket(float a[],int n){
    vector<float> bucket[n];

    for(int i = 0 ; i < n ; i++) {
        int index = n * a[i];

        bucket[index].push_back(a[i]);
    }

    for(int i = 0 ; i < n ; i++) {
        sort(bucket[i].begin(),bucket[i].end());
    }

    int k = 0;
    for(int i = 0 ; i < n ; i++) {
        for(auto x : bucket[i]){
            a[k] = x;
            k++;
        }
    }

    cout << endl << "Sorted Array : ";
    for(int i = 0 ; i < n ; i++) {
        cout << a[i] << " " ;
    }
}


int main(){
    int n;
    cout << "Enter the size : ";
    cin >> n;

    float arr[n];
    cout << "Enter the " << n << " elements : ";

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    bucket(arr,n);
}