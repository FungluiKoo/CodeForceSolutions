#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long k, sum=0, result=0;
    std::cin >> k;
    char ch, cnt[10];

    for(int i=0; i<10; i++){
        cnt[i] = 0;
    }
    while(std::cin.get(ch)){
        if(ch>='0'&&ch<='9'){
            cnt[ch-'0']++;
            sum += long(ch-'0'); 
        }
    }
    
    for(int i=0; sum<k && i<9; ++i){
        while(sum<k && cnt[i]>0){
            sum += long(9-i);
            result++;
            cnt[i]--;
        }
    }
    std::cout << result;
    return 0;
}