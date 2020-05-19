#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#define N 3001

using namespace std;

vector<unsigned int>* generatePrimes(){ //produce primes smaller than N
    // stores all the prime numbers
    vector<unsigned int> *primes = new vector<unsigned int>;
    // indicating prime or not
    bitset<N> tmparr;
    // set all integers [0,N-1] as prime
    tmparr.set();
    // detect all non primes in [0,N-1]
    tmparr.reset(0); // 0 is not prime
    tmparr.reset(1); // 1 is not prime
    for(unsigned int p=2;p<N;p++){
        if(tmparr.test(p)){ // when p is prime
            for(unsigned int i=2*p;i<N;i+=p){tmparr.reset(i);} //set multiples as not prime
            primes->push_back(p); //store the prime number
        }
    }
    return primes;
}

int main(){
    unsigned int n=0, cnt=0;
    cin >> n;
    vector<unsigned int>* primes = generatePrimes();
    char* arr = new char[n+1];
    for(unsigned int i=0; i<=n; i++){arr[i]=0;}
    for(auto iter = primes->begin(); iter != primes->end(); iter++) {
        unsigned int p=*iter;
        for(unsigned int i=p;i<=n;i+=p){arr[i]++;}
    }
    for(unsigned int i=0; i<=n; i++){
        if(arr[i]==2){cnt++;}
    }
    cout << cnt << endl;
    delete arr;
    delete primes;
    return 0;
}