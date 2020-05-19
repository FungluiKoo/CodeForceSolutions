#include <iostream>

#define M 1001

int main(){
    short n, length, max_height=0, tower_cnt=0;
    short arr[M] {};
    std::cin >> n;
    for(short i=0; i<n; ++i){
        std::cin >> length;
        if(arr[length]==0){
            ++tower_cnt;
        }
        if(++arr[length]>max_height){
            max_height = arr[length];
        }
    }
    std::cout << max_height << " " << tower_cnt << std::endl;
    return 0;
}