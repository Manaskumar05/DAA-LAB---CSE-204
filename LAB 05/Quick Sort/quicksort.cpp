#include <iostream>
using namespace std;

int partition(int a[],int low,int high){
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while(i < j) {
        while(i <= high && pivot >= a[i]){
            i++;
        }
        while(j >= low && pivot < a[j]){
            j--;
        }

        if(i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;

}

int quicksort(int a[],int low,int high) {
    if(low < high){
        int p = partition(a,low,high);

        quicksort(a,low,p - 1);
        quicksort(a,p + 1,high);
    }
}
int main(){

    int n;
    cout << "Enter the size : ";
    cin >> n;

    int arr[n];
    cout << "Enter the " << n << " elements : ";

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    quicksort(arr,0,n - 1);

    cout << endl << "Sorted Array : ";
    for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << " " ;
    }
}