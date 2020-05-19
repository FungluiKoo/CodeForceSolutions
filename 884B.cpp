#include <iostream>

int main(){
    long n, x, length, sum=0;
    std::cin >> n >> x;
    for(long i=0; i<n; ++i){
        std::cin >> length;
        sum+=length;
    }
    std::cout << ((sum+n-1==x)?"YES":"NO") << std::endl;
    return 0; 
}