#include <iostream>
#include <set>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    bool flag = true;
    for(int i=0; flag && i<m; ++i){
        std::set<int> member;
        flag = false;
        int k;
        std::cin >> k;
        for(int j=0; j<k; ++j){
            int v;
            std::cin >> v;
            if(member.count(-v)){
                flag = true;
            }
            member.insert(v);
        }
    }
    if(flag){
        std::cout << "NO\n";
    }else{
        std::cout << "YES\n";
    }
    return 0;
}