#include <iostream>
#include <bitset>
#define N 1000001

using namespace std;

int main(){
    unsigned short n=0, m=0;
    cin >> n >> m;
    bitset<N> arr;
    while(n || m){
        arr.reset();
        bool overlap=false;
        for(unsigned short i=0; i<n; i++){ //read the one time events
            unsigned int s=0, f=0;
            cin >> s >> f;
            if(!overlap){
                for(unsigned int t=s; t<f; t++){
                    if(arr.test(t)){
                        overlap=true;
                        break;
                    }else{
                        arr.set(t);
                    }
                }
            }
        }
        for(unsigned short i=0; i<m; i++){ //read the repeated events
            unsigned int s=0, f=0, pr=0;
            cin >> s >> f >> pr;
            if(!overlap){
                for(unsigned int t0=s; t0<N; t0+=pr){
                    for(unsigned int t=t0; t<N && t<t0+f-s; t++){
                        if(arr.test(t)){
                            overlap=true;
                            break;
                        }else{
                            arr.set(t);
                        }
                    }
                    if(overlap){break;}
                }
            }
        }
        if(overlap){
            cout << "CONFLICT" << endl;
        }else{
            cout << "NO CONFLICT" << endl;
        }
        cin >> n >> m;
    }
    return 0;
}