//2. Write a program to find the Kth smallest element in the array.

#include <iostream>
using namespace std;

void sort(int a[],int n){
    for (int i = 0 ; i < n ; i++) {
        for(int j = i ; j < n - 1 ; j++) {
            if(a[j + 1] > a[j]) {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of array : ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements in array : ";
    for(int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }

    sort(arr,size);

    int k;
    cout << "Enter the value of k : ";
    cin >> k;
    
    cout << "kth smallest element in given array : " << arr[k - 1];

    return 0;
}