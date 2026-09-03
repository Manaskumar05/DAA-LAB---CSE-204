#include <iostream>
using namespace std;

void merge(int a[],int low,int mid,int high){
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[100];

    while(i <= mid && j <= high){
        if(a[i] >= a[j]) {
            b[k] = a[j];
            j++;
        }
        else {
            b[k] = a[i];
            i++;
        }
        k++;
    }

    while(i <= mid){
        b[k] = a[i];
        k++;
        i++;
    }

    while(j <= high){
        b[k] = a[j];
        k++;
        j++;
    }

    for(int i = low ; i <= high ; i++){
        a[i] = b[i];
    }

}
void mergesort(int a[],int low,int high){
    if(low < high) {
        int mid = (low + high) / 2;

        mergesort(a,low,mid);
        mergesort(a,mid + 1,high);

        merge(a,low,mid,high);
    }
}

int main() {

    int n;
    cout << "Enter the size : ";
    cin >> n;

    int arr[n];
    cout << "Enter the " << n << " elements : ";

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    mergesort(arr,0,n - 1);

    cout << endl << "Sorted Array : ";
    for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << " " ;
    }
}