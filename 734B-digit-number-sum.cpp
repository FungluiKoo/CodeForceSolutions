#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long cnt[7]={};
    long long cnt_256=__LONG_LONG_MAX__, cnt_32=__LONG_LONG_MAX__;

    //read inputs
    for(short i : {2,3,5,6}){
        std::cin >> cnt[i];
    }
    // get as much 256 as possible
    for(short i : {2,5,6}){
        cnt_256 = (cnt[i]<cnt_256) ? cnt[i] : cnt_256;
    }
    for(short i: {2,5,6}){
        cnt[i] -= cnt_256;
    }
    // then get 32
    for(short i: {3,2}){
        cnt_32 = (cnt[i]<cnt_32) ? cnt[i] : cnt_32;
    }
    
    std::cout << (cnt_256*256ll + cnt_32*32ll) << std::endl;
    return 0;
}