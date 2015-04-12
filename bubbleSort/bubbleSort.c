//  Created by Farkhad Alizade on 11/04/2015.
//  Copyright (c) 2015 farkhad-alizade. All rights reserved.

#include <stdio.h>

int* bubbleSort(int arr[] , int n);

int main(int argc, const char * argv[]) {

    int arr[] = {-12 , 12 , 12 , 6 , 7 , 8, 9 ,-10 , -11};
    int i;
    int n = 9;
    
    int *sortedArray = bubbleSort(arr , n);
    
    for(i = 0 ; i < n ; i++){
        printf("%d, " ,  sortedArray[i]);
    }
    
    return 0;
}


int* bubbleSort(int arr[] , int n){
    int i;
    int j;
    double tmp;

    for( i = 0 ; i < n ; i++ ){
        for( j = 0 ; j < n-i-1 ; j++ ){
            if( arr[j] > arr[j + 1] ){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    
    return arr;
}