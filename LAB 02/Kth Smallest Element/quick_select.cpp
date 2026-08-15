//2. Write a program to find the Kth smallest element in the array.

#include <iostream>
using namespace std;

int partition(int a[],int low,int high){
    int pivot = a[high];
    int i = low - 1;

    for(int j = low ; j < high ; j++) {
        if(a[j] < pivot) {
            i++;

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    
    int temp = a[high];
    a[high] = a[i + 1];
    a[i + 1] = temp;

    return i + 1;
}

int sort(int a[],int low,int high,int k) {
    int pivot_index = partition(a,low,high);
    
    if(pivot_index == k - 1) {
        return a[k - 1];
    }

    else if(k - 1< pivot_index) {
        return sort(a,low,pivot_index - 1,k);
    }

    else if(k > pivot_index) {
        return sort(a,pivot_index + 1,high,k);
    }


    return -1;
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
    int k;
    cout << "Enter the value of k : ";
    cin >> k;

    sort(arr,0,size - 1,k);
    
    cout << "kth smallest element in given array : " << arr[k - 1];

    return 0;
}