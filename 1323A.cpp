#include <iostream>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    short t, n, a;
    std::cin >> t;
    for(short i=0; i<t; i++){
        std::cin >> n;
        bool odd_found = false, even_found=false;
        short idx, checkpoint;
        for(short j=1; j<=n; j++){
            std::cin >> a;
            if(a & 0x0001){ // odd
                if(!odd_found){ // first odd
                    idx = j;
                    odd_found = true;
                }else{ // second odd
                    std::cout << "2\n" << idx << " " << j << std::endl;
                    even_found = true;
                    checkpoint = j;
                    break;
                }
            }else{ // even
                std::cout << "1\n" << j << std::endl;
                even_found = true;
                checkpoint = j;
                break;
            }
        }
        for(short j=checkpoint+1;j<=n;j++){
            std::cin >> a;
        }
        if(!even_found){
            std::cout << "-1" << std::endl;
        }
    }
    return 0;
}