#include <iostream>

using namespace std;

int main(){
    unsigned short odd_1=0, even_1=0, n=0, odd_cnt=0, even_cnt=0;
    cin >> n;
    for(unsigned short i=0; i<n; i++){
        unsigned short k;
        cin >> k;
        if(k%2==1){
            if(odd_cnt==0){odd_1 = i;}
            odd_cnt++;
        }else{
            if(even_cnt==0){even_1 = i;}
            even_cnt++;
        }
        if(odd_cnt==1 && even_cnt>1){
            cout << odd_1+1 << endl;
            break;
        }else if(even_cnt==1 && odd_cnt>1){
            cout << even_1+1 << endl;
            break;
        }
    }
    return 0;
}