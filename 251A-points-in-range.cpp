#include <iostream>

unsigned long long select2From(unsigned long long k){
    return (k*(k-1ull))>>1;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); 
    unsigned long long n=0;
    long long d=0;
    std::cin >> n >> d;
    auto x = new long long[n];
    unsigned long long result=0ull, left=0ull;
    for(unsigned long long i=0; i<n; i++){
        std::cin >> x[i];
        while(x[left]+d < x[i]){left++;}
        result += select2From(i-left);
    }
    std::cout << result;
    delete[] x;
    return 0;
}