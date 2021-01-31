#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<long> arr;
    arr.push_back(INT32_MIN);

    for(int i=0; i<n; ++i){
        int a;
        std::cin >> a;
        arr.push_back(a);
    }

    auto curr = ++(arr.cbegin());
    auto start = ++(arr.cbegin());
    auto mark = arr.cbegin();
    int result = 0;

    
    while(start != arr.cend()){
        int prev = *curr;
        while(++curr != arr.cend()){
            if(*curr > prev){ // strictly increasing
                prev = *curr;
            }else if(mark == arr.cbegin()){ // first time not strictly increasing
                mark = curr;
                if(*curr > *(curr-2)+1){
                    // treat prev as if it were *(curr-2)+1
                    prev = *curr;
                }else{
                    prev += 1; // treat *curr as if it were prev+1
                }
            }else{ // second time not strictly increasing
                break;
            }
        }

        // segment length = curr - start
        result = std::max(result, int(curr - start));

        if(curr == arr.cend()){
            break;
        }else{
            // prepare for next
            start = curr = mark;
            mark = arr.cbegin();
        }
    }

    std::cout << result;

    return 0;
}