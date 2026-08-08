#include <stdio.h>

int linear_search(int arr[] ,int n ,int key) {

    for(int i = 0 ; i < n ; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main () {

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

    int result = linear_search(arr, n , key);

    if(result == -1) {
        printf("Not found");
    }
    else{
        printf("Found at index %d",result);
    }

    return 0;
}