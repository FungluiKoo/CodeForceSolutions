#include <iostream>
#include <bitset>
#include <cmath>
#define N 1001

using namespace std;

bool isLucky(unsigned int n){
    while(n){
        if(n%10==4 || n%10==7){
            n/=10;
        }else{
            return false;
        }
    }
    return true;
}

// bool isAlmostLucky(unsigned int n){
//     for(unsigned int i=1; i<=sqrt(n); i++){
//         if(n%i==0){
//             if(isLucky(i) || isLucky(n/i)){return true;}
//         }
//     }
//     return false;
// }

int main(){
    unsigned int n;
    cin >> n;
    bitset<N> arr;
    arr.reset();
    for(unsigned int i=2; i<=n; i++){
        if(!arr.test(i) && isLucky(i)){
            for(unsigned int j=i; j<=n; j+=i){arr.set(j);}
        }
    }
    if(arr.test(n)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}