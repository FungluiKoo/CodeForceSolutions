#include <iostream>
#include <numeric>
#include <queue>

int main(){
    long long dasha_interval, masha_interval;
    std::cin >> dasha_interval >> masha_interval;
    long long gcd = std::gcd<long long,long long>(dasha_interval, masha_interval);
    dasha_interval/=gcd;
    masha_interval/=gcd;
    if(std::abs(dasha_interval-masha_interval)<=1){
        std::cout << "Equal";
    }else{
        std::cout << ((dasha_interval>masha_interval) ? "Masha" : "Dasha");
    }
    return 0;
}