#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long k, sum=0l, result=0l;
    std::cin >> k;
    char ch, cnt[10];
    int i=0;
    for(int i=0; i<10; i++){
        cnt[i] = 0;
    }
    while(std::cin.get(ch)){
        if(ch>='0'&&ch<='9'){
            cnt[ch-'0']++;
            sum += long(ch-'0');
            i++;   
        }
    }
    
    for(long i=0l;sum<k && i<10l; i++){
        while(sum<k && cnt[i]>0){
            sum += 9l-i;
            result++;
            cnt[i]--;
        }
    }
    std::cout << result;
    return 0;
}