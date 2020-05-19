#include <iostream>

using namespace std;

int main(){
    register unsigned short n, i=0, cnt_i=0;
    string muscle[3]={"chest","biceps","back"};
    unsigned short cnt_total[3]={0};
    // read first line
    cin >> n;
    // read second line
    for(i=0;i<n;i++){
        cin >> cnt_i;
        cnt_total[i%3]+=cnt_i;
    }
    // find the max
    unsigned short ex_max=0;
    for(i=1;i<3;i++){
        if(cnt_total[i] > cnt_total[ex_max]){ex_max=i;}
    }
    // output
    cout << muscle[ex_max] << endl;
    return 0;
}
