//  Created by Farkhad Alizade on 14/04/2015.
//  Copyright (c) 2015 farkhad-alizade. All rights reserved.

#include <stdio.h>

int* quickSort(int arr[] , int left , int right);

int main(int argc, const char * argv[]) {
    
    int arr[] = {-12 , 20 , 12 , 4 , 21 , 8, -14 ,-10 , -11};
    int i;
    int n = 9;
    
    int *sortedQuickArray = quickSort(arr, 0, n);
    
    for(i = 0 ; i < n ; i++){
        printf("%d, " ,  sortedQuickArray[i]);
    }
    
    return 0;
}


int* quickSort(int arr[] , int left , int right){
    int i = left;
    int j = right;
    int centerElementIndex = (right + left)/2;
    int centerElement = arr[centerElementIndex];
    int tmp;
    
    while(i <= j ){
        
        while(arr[i] < centerElement){
            i++;
        }
        
        while(arr[j] > centerElement){
            j--;
        }
        
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
        
    }
        
    if (left < j){
        quickSort(arr, left, j);
    }
    
    if (i < right){
        quickSort(arr, i, right);
    }
    
    return arr;
}
