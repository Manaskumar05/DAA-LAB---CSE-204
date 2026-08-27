#include <iostream>
#define size 10
using namespace std;

int main() {

    int hashtable[size];
    for(int i = 0 ; i < size ; i++) {
        hashtable[i] = -1;
    }



    int n,key;
    cout << "Enter the size of array : ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of array : ";
    for(int i = 0 ; i < n ; i++) {
        cin >> key;

        int index = key % size;

        while(hashtable[index] != -1 ){
            index = (index + 1) % size;
        }
        hashtable[index] = key;
    }

    
    cout << "---HashTable---" << endl;
    for(int i = 0 ; i < size ; i++) {
        cout << "At index " << i << " --> " << hashtable[i] << endl;
    }


    return 0;
}