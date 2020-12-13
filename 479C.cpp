#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<long, long> Exam;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    short exam_cnt;
    std::cin >> exam_cnt;
    std::vector<Exam> exams;
    long result=0;
    for(short i=0; i<exam_cnt; ++i){
        long a, b;
        std::cin >> a >> b;
        exams.push_back({a,b});
    }

    std::sort(exams.begin(), exams.end(), [](const Exam &a, const Exam &b){
        return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
    });

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