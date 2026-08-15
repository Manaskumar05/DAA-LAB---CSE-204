//Programs for summation of series 1+X+X^2+X^3+…with different time complexities.


#include <iostream>
#include <math.h>
using namespace std;

int gp_sum(int r,int n) {
    int a = 1;
    int sum = a * ((pow(r , n) - 1) / (r - 1));
    return sum;
}



int main() {

    int r,n;
    cout << "Enter the commom ratio : ";
    cin >> r;

    cout << "Enter number of terms in Geometric Progression : ";
    cin >> n;

    int ans = gp_sum(r , n);

    cout << "Sum of given Geometric Progression : "<< ans;

    return 0;
}