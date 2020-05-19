#include <iostream>
#include <algorithm>

long helper(long *arr, long h_base, long left, long right){
    if(left>right){
        return 0l;
    }else{
        long h_min = __LONG_MAX__;
        long h_min_idx = -1;
        for(long i=left; i<=right; ++i){
            if(arr[i]<h_min){
                h_min = arr[i];
                h_min_idx = i;
            }
        }
        return std::min(right-left+1l, \
                        h_min-h_base+helper(arr, h_min, left, h_min_idx-1) + \
                        helper(arr, h_min, h_min_idx+1, right));
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long n;
    std::cin >> n;
    auto arr = new long[n];
    for(long i=0; i<n; i++){
        std::cin >> arr[i];
    }
    std::cout << helper(arr, 0, 0, n-1);
    delete[] arr;
    return 0;
}