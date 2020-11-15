#include <algorithm>
#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> kangaroos;
    int n;
    std::cin >> n;
    for(int i=0; i<n; ++i){
        int kangaroo;
        std::cin >> kangaroo;
        kangaroos.push_back(kangaroo);
    }
    std::sort(kangaroos.begin(), kangaroos.end());
    
    int cnt = n;
    auto mid = kangaroos.begin() + n/2;
    std::vector<int> small(kangaroos.begin(), mid);
    std::vector<int> big(mid, kangaroos.end());
    
    while(true){
        while(!small.empty() && big.back() < small.back()*2){
            small.pop_back();
        }
        if(small.empty()){
            break;
        }
        big.pop_back();
        small.pop_back();
        --cnt;
    }

    std::cout << cnt;
    return 0;
}