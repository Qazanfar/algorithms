//  Created by Farkhad Alizade on 15/04/2015.
//  Copyright (c) 2015 farkhad-alizade. All rights reserved.

#include <stdio.h>

int* sieveSort(int arr[] , int n);

int main(int argc, const char * argv[]) {
    
    int arr[] = {31 , 3 , -1 , 1 , 2 , 2, 0 ,31 , -1};
    int i;
    int n = 9;
    
    int *sortedSeaveSort = sieveSort(arr, n);
    
    for(i = 0 ; i < n ; i++){
        printf("%d, " ,  sortedSeaveSort[i]);
    }
    
    return 0;
}


int* sieveSort(int arr[] , int n){
    int i;
    int k;
    int tmp;
    
    for(i = 0 ; i < n  ; i++ ){
        if(arr[i] > arr[i+1]){
            tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
            
            for( k = i ; k > 0 ; k--){
                if(arr[k - 1] > arr[k]){
                    tmp = arr[k];
                    arr[k] = arr[k - 1];
                    arr[k - 1] = tmp;
                }else{
                    break;
                }
            }
        }
    }
    
    return arr;
}
