#include <cstdio>

using namespace std;

int main(){
    unsigned long n=0, q=0;
    scanf("%lu %lu", &n, &q);
    unsigned long *group = new unsigned long[n];
    unsigned long *rank = new unsigned long[n];
    for(unsigned long i=0; i<n; i++){
        group[i]=i;
        rank[i]=0;
    }
    for(unsigned long i=0; i<q; i++){
        char op;
        unsigned long a=0, b=0;
        scanf(" %c %lu %lu", &op, &a, &b);
        unsigned long aid = a, bid = b;
        while(group[aid]!=aid){
            aid = group[aid];
        }
        while(group[bid]!=bid){
            bid = group[bid];
        }
        if(op=='?'){
            if(aid==bid){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }else if(op=='='){
            if(rank[aid]==rank[bid]){
                rank[aid]++;
                group[bid]=aid;
            }else if(rank[aid]>rank[bid]){
                group[bid]=aid;
            }else{
                group[aid]=bid;
            }
        }
    }
    delete[] group;
    delete[] rank;
    return 0;
}