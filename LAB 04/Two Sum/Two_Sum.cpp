#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n,target;
    cout << "Enter size of array : ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of array : ";
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target value : ";
    cin >> target;

    unordered_set <int> seen;

    for(int i = 0 ; i < n ; i++) {
        int required = target - arr[i];

        if(seen.find(required) != seen.end()) {
            cout << arr[i] << " + " << required << " = " << target << endl; 
        }

        seen.insert(arr[i]);
    }
    
}