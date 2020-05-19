#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); 
    unsigned short test_cnt, arr_size;
    std::cin >> test_cnt;
    for(unsigned short t=0; t<test_cnt; ++t){
        std::cin >> arr_size;
        auto arr = new short[arr_size];
        long long sum=0;
        unsigned short zero_cnt=0;
        for(unsigned short i=0; i<arr_size; ++i){
            std::cin >> arr[i];
            sum+=arr[i];
            if(arr[i]==0){
                ++zero_cnt;
            }
        }
        delete[] arr;

        std::cout << ((sum+zero_cnt) ? zero_cnt : (zero_cnt+1)) << std::endl;
    }
    return 0;
}