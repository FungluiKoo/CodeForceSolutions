#include <iostream>
#include <map>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    short exam_cnt;
    std::cin >> exam_cnt;
    std::multimap<long, long> exams;
    long result=0;
    for(short i=0; i<exam_cnt; ++i){
        long a, b;
        std::cin >> a >> b;
        exams.insert({a,b});
    }
    for(auto iter = exams.begin(); iter!=exams.end(); ++iter){
        if(iter->second >= result){
            result = iter->second;
        }else{
            result = iter->first;
        }
    }
    std::cout << result;
    return 0;
}