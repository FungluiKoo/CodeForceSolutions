#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for(int i=1; i<=n; ++i){
        for(int j=0; j<n; j+=2){
            std::cout << (j*n+i) << " " << ((j+2)*n+1-i) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}