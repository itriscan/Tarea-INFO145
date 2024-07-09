int busquedaBinaria(int n, const int* A, int s){
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = (l + r)/2;
        if(A[mid] == s){
            return mid;
        }
        if (A[mid] < s){
            
            l = mid+1;
        }else{
            r = mid - 1;
        }
    }
    return -1;
}