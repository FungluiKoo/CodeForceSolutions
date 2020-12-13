#include <iostream>

#define N 100001

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    auto cnt = new int[N];
    auto dp = new long long[N];
    
    for(int i=0; i<N;++i){
        cnt[i] = 0;
    }

    int n, a;
    std::cin >> n;

    for(int i=0; i<n; ++i){
        std::cin >> a;
        ++cnt[a];
    }

    dp[0] = 0;
    dp[1] = cnt[1];
    for(long long i=2; i<N; ++i){
        dp[i] = std::max(dp[i-1], dp[i-2] + i*cnt[i]);
    }

    std::cout << dp[N-1];

    delete[] cnt;
    delete[] dp;
    return 0;
}