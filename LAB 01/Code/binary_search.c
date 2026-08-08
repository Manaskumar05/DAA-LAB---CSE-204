#include <stdio.h>

//Sorting

int sort(int a[],int n) {
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j = n - i - 1 ; j++) {
            if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int binary_search(int a[],int n,int key) {
    int start = 0;
    int end = n - 1;
    int mid;
    while(start <= end) {
        mid = (start + end) / 2;
        
        if(a[mid] == key) {
            return mid;
        }
        else if(key < mid) {
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return -1;
}

int main() {

    int n,key;

    printf("Enter the size of array : ");
    scanf("%d",&n);
    
    int arr[n];
    
    printf("Enter the %d elements of array : ",n);
    for(int i = 0 ; i < n ; i++) {
        scanf(" %d",&arr[i]);
    }
    
    
    printf("Enter the number to search : ");
    scanf("%d",&key);


    int result = binary_search(arr, n , key);

    if(result == -1) {
        printf("Not found");
    }
    else{
        printf("Found at index %d",result);
    }


    return 0;
}