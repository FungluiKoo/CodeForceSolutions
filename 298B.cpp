#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    long x0, y0, x1, y1;
    std::cin >> x0 >> y0 >> x1 >> y1;
    long x = x1-x0, y = y1-y0;

    int i=0;
    for(; (x||y) && i<t; ++i){
        char dir;
        std::cin >> dir;
        switch (dir){
            case 'E':
                if(x>0){
                    --x;
                }
                break;
            case 'W':
                if(x<0){
                    ++x;
                }
                break;
            case 'N':
                if(y>0){
                    --y;
                }
                break;
            case 'S':
                if(y<0){
                    ++y;
                }
                break;
            default:
                break;
        }
    }
    if(x || y){
        std::cout << -1;
    }else{
        std::cout << i;
    }
    return 0;
}