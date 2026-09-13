#include <iostream>
using namespace std;

pair<int,int> findmin_max(int arr[],int low,int high){
    if(low == high){
        return {arr[low],arr[low]};
    }

    int mid = (low + high) / 2;
    pair<int,int> left = findmin_max(arr,low,mid);
    pair<int,int> right = findmin_max(arr,mid + 1 , high);

    int minimum = min(left.first, right.first);
    int maximum = max(left.second, right.second);

    return {minimum, maximum};

}

int main() {
    int arr[5] = {22,55,88,44,66};
    pair<int,int> result = findmin_max(arr,0,4);

    cout << "Minimum : " << result.first << endl;
    cout << "Maximum : " << result.second;

}