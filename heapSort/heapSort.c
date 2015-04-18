#include <stdio.h>

int* heapSort(int arr[] , int n);
int maxOfIndex(int arr[] , int , int);

typedef enum { false, true } bool;

int buidTriangle(int arr[] , int , int , bool);

int main(int argc, const char * argv[]) {
    
    int arr[] = { 13 , 2 , 4 , 5 , -6 , 3 , 1 , -10 };
    int i;
    int n = 8;
    
    int *sortedHeapkArray = heapSort(arr, n);
    
    
    for(i = 0 ; i < n ; i++){
        printf("%d, " ,  sortedHeapkArray[i]);
    }
    
    return 0;
}


int* heapSort(int arr[] , int n){
    int k = 0;
    int s = 0;
    int isBuild = 0;
    int tmp;
    
    buidTriangle(arr, n, 0 , false);
    
    for( k = 3 ; k < n ; k++){
        s = (k-1)/2;
        while(s >= 0){
            isBuild = buidTriangle(arr , n , s , false);
            if(isBuild == -1){
                break;
            }
            s = (s - 1)/2;
        }
    }
    
    
    for(k = n ; k > 0 ; k--){
        
        tmp = arr[0];
        arr[0] = arr[k - 1];
        arr[k-1] = tmp;
        
        isBuild = 0;
        
        while(1){
            isBuild = buidTriangle(arr, k - 1   , isBuild , true);
            if(isBuild == -1){
                break;
            }
        }
    }
    
    return arr;
}

int buidTriangle(int arr[] , int n ,  int s , bool isDismantling){
    int tmp;
    int tmpIndex;
    
    if( s*2 + 1 > n - 1 ){
        return -1;
    }else if( s*2 + 1 == n - 1  ){
        tmpIndex = n - 1;
    }else{
        tmpIndex = maxOfIndex(arr , s*2 + 1 , s*2 + 2);
    }
    
    if( arr[s] < arr[tmpIndex] ){
        tmp = arr[s];
        arr[s] = arr[tmpIndex];
        arr[tmpIndex] = tmp;
        
        return tmpIndex;
    }else{
        return -1;
    }
    
    
}


int maxOfIndex(int arr[] , int aIndex , int bIndex){
    if(arr[aIndex] > arr[bIndex]){
        return aIndex;
    }else{
        return bIndex;
    }
}