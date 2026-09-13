#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size : ";
    cin >> n;

    int weight[n];
    int profit[n];
    double ratio[n];

    for(int i = 0 ; i < n ; i++) {
        cin >> weight[i];
    }

    for(int i = 0 ; i < n ; i++) {
        cin >> profit[i];
    }
    
    for(int i = 0 ; i < n ; i++) {
        ratio[i] = (double)profit[i] / weight[i];
    }
    
    int max_weight;
    cout << "Enter max weight : ";
    cin >> max_weight;
    
    int rem_weight = max_weight;
    double max_profit = 0;
    
    while(rem_weight != 0) {
    
        int max_index = 0;
    
        for(int i = 1; i < n; i++) {
            if(ratio[i] > ratio[max_index]) {
                max_index = i;
            }
        }
    
        if(rem_weight >= weight[max_index]) {
            max_profit += profit[max_index];
            rem_weight -= weight[max_index];
        }
        else {
            max_profit += (double)rem_weight / weight[max_index] * profit[max_index];
            rem_weight = 0;
        }
    
        ratio[max_index] = -1;
    }
    
    cout << "Max profit : " << max_profit;
}