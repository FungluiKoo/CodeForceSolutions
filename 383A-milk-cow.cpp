#include <iostream>
#include <bitset>

#define N 200001

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); 
    unsigned long long n, lookRight=0, result=0;
    std::cin >> n;
    std::bitset<N> dir;
    dir.reset();
    
    for(unsigned long long i=0; i<n; i++){
        unsigned short direction;
        std::cin >> direction;
        if(direction){ // looking right
            dir.set(i);
            lookRight++;
        }else{ // looking left
            result += lookRight;
        }
    }
    std::cout << result << std::endl;
    return 0;
}