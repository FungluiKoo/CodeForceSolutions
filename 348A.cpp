#include <iostream>

using namespace std;

int main(){
    unsigned long long n=0, amax=0, sum=0;
    cin >> n;
    unsigned long long *a=new unsigned long long[n];
    for(unsigned long long i=0; i<n; i++){
        cin >> a[i];
        amax=(a[i]>amax)?a[i]:amax;
    }
    for(unsigned long long i=0;i<n;i++){
        sum+=(amax-a[i]);
    }
    if(sum>=amax){
        cout << amax << endl;
    }else{
        cout << amax + (amax-sum+n-2)/(n-1) << endl;
    }
    delete a;
    return 0;
}