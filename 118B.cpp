#include <iostream>

using namespace std;

int main(){
    short n;
    cin >> n;
    for(short i=0; i<=n; i++){
        for(short j=0; j<n-i; j++){cout <<"  ";}
        for(short j=0; j<i; j++){cout << j << " ";}
        for(short j=i; j>0; j--){cout << j << " ";}
        cout << "0" << endl;
    }
    for(short i=n-1; i>=0; i--){
        for(short j=0; j<n-i; j++){cout <<"  ";}
        for(short j=0; j<i; j++){cout << j << " ";}
        for(short j=i; j>0; j--){cout << j << " ";}
        cout << "0" << endl;
    }
    return 0;
}