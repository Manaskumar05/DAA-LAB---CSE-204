#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

void move(stack <int>& x,stack <int>& y,char a,char b) {
    if(x.empty()){
        int disk = y.top();
        y.pop();
        x.push(disk);
        cout << "Move " << disk << " from " << b << " to " << a << endl;
    }
    
    else if(y.empty()){
        int disk = x.top();
        x.pop();
        y.push(disk);
        cout << "Move " << disk << " from " << a << " to " << b << endl;
    }
    
    else {
        if(x.top() > y.top()) {
            int disk = y.top();
            y.pop();
            x.push(disk);
            cout << "Move " << disk << " from " << b << " to " << a << endl;
        }
        else {
            int disk = x.top();
            x.pop();
            y.push(disk);
            cout << "Move " << disk << " from " << a << " to " << b << endl;
        }
    }

}

void TOH(int n) {
    stack <int> A,B,C;

    char a = 'A';
    char b = 'B';
    char c = 'C';

    for(int i = n ; i > 0 ; i--) {
        A.push(i);
    }

    int total_moves = pow(2,n) - 1;

    if(n % 2 == 0) {
        swap(B,C);
        swap(b,c);
    }

    for(int i = 1 ; i <= total_moves ; i++) {
        if(i % 3 == 1) {
            move(A,C,a,c);
        }
        else if(i % 3 == 2) {
            move(A,B,a,b);
        }
        else if(i % 3 == 0) {
            move(C,B,c,b);
        }
    }

}

int main() {
    int n;
    cout << "Enter no of disks : " ;
    cin >> n;

    TOH(n);

    return 0;
}