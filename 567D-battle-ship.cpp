#include <iostream>
#include <map>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::map<int,char> checkpoint;
    int n, k, a, m, k_max, result=-1;
    std::cin >> n >> k >> a >> m;
    checkpoint[0]=1;
    checkpoint[n+1]=1;
    k_max = (n+1)/(a+1);
    for(int i=1; i<=m ; i++){
        int x;
        std::cin >> x;
        checkpoint[x]=1;
        auto search = checkpoint.find(x);
        int left_neighbor = (--search)->first;
        ++search;
        int right_neighbor = (++search)->first;
        int ships_original = (right_neighbor-left_neighbor)/(a+1);
        int ships_new = (x-left_neighbor)/(a+1) + (right_neighbor-x)/(a+1);
        k_max -= (ships_original - ships_new);
        if(k_max<k){
            result=i;
            break;
        }
    }
    std::cout << result;
    return 0;
}