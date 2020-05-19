#include <iostream>
#include <list>

using namespace std;

int main(){
    unsigned long long n;
    cin >> n;
    list<unsigned long long> arr;
    for(unsigned long long i=0; i<n; i++){
        unsigned long long k;
        cin >> k;
        arr.push_front(k);
    }
    arr.sort();
    unsigned long long i=2, sum=0;
    for(auto iter = arr.cbegin(); iter !=arr.cend(); iter++){
        sum+= (*iter)*i;
        i++;
    }
    if(!arr.empty()){sum-=arr.back();}
    cout << sum << endl;
    return 0;
}