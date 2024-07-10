#include "binarySearch.h"

int busquedaBinaria(int n,  int *A, int s){
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = l + (r-l)/2;
        if(A[mid] == s){
            return mid;
        }
        else if (A[mid] < s){
            
            l = mid+1;
        }else{
            r = mid - 1;
        }
    }
    return -1;
}