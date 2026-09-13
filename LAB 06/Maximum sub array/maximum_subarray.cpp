#include <iostream>
#include <climits>
using namespace std;

int maxCrossingSum(int a[], int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--) {
        sum += a[i];
        leftSum = max(leftSum, sum);
    }

    int rightSum = INT_MIN;
    sum = 0;

    for (int i = mid + 1; i <= high; i++) {
        sum += a[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarray(int a[], int low, int high) {
    if (low == high)
        return a[low];

    int mid = (low + high) / 2;

    int left = maxSubarray(a, low, mid);
    int right = maxSubarray(a, mid + 1, high);
    int cross = maxCrossingSum(a, low, mid, high);

    return max(left, max(right, cross));
}

int main() {
    int a[] = {-2, 5, -1, 3, -4};
    int n = 5;

    cout << "Maximum Subarray Sum = "
         << maxSubarray(a, 0, n - 1);

    return 0;
}