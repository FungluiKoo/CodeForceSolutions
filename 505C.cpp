#include <iostream>
#include <vector>

#define N 30001
#define OFFSET 250

int arr[N] = {};
int dp[N][2*OFFSET];

int d;

int helper(int pos, int l);

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    for(int i=0; i<N; ++i){
        for(int j=0; j<2*OFFSET; ++j){
            dp[i][j] = -1;
        }
    }

    int n;
    std::cin >> n >> d;
    for(int i=0; i<n; ++i){
        int pos;
        std::cin >> pos;
        ++arr[pos];
    }
    std::cout << helper(d,d);

    return 0;
}

int helper(int pos, int l){
    if(pos>=N){return 0;}
    if(dp[pos][l-d+OFFSET]!=-1){return dp[pos][l-d+OFFSET];}
    int result = arr[pos] + std::max(helper(pos+l,l), helper(pos+l+1,l+1));
    if(l>1){result = std::max(result, arr[pos] + helper(pos+l-1,l-1));}
    dp[pos][l-d+OFFSET] = result;
    return result;
}