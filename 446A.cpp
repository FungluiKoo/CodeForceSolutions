#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<long> arr;
    std::vector<int> left(n, 0);
    std::vector<int> right(n, 0);

    for(int i=0; i<n; ++i){
        int a;
        std::cin >> a;
        arr.push_back(a);
    }

    for(int i=1; i<n; ++i){
        if(arr[i] > arr[i-1]){
            left[i] = left[i-1] + 1;
        }else{
            left[i] = 0;
        }
    }

    for(int i=n-2; i>=0; --i){
        if(arr[i] < arr[i+1]){
            right[i] = right[i+1] + 1;
        }else{
            right[i] = 0;
        }
    }

    int result;
    if(n<3){
        result = n;
    }else{
        result = 2 + std::max(right[1], left[n-2]);
        for(int i=1; i<n-1; ++i){
            if(arr[i-1] > arr[i+1]-2){
                result = std::max(result, 2 + std::max(left[i-1], right[i+1]));
            }else{
                result = std::max(result, 3 + left[i-1] + right[i+1]);
            }
        }
    }
    
    std::cout << result;

    return 0;
}