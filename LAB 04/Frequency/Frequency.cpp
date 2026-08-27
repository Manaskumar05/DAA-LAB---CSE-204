#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of n : ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements of array : ";
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    unordered_map<int,int> frequency;

    for(int i = 0 ; i < n ; i++) {
        frequency[arr[i]]++;
    }

    cout << "Frequency of elements : " << endl;

    for(auto x : frequency) {
        cout << x.first << " --> " << x.second << " times" << endl;
    }

    
}