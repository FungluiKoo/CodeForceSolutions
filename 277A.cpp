#include <iostream>
#include <vector>

class DisjointSet{
private:
    bool *isused;
    long *parent;
    long *size;
    long n;
    long largest_size;
    long group_cnt;
    long getRoot(long idx);

public:
    DisjointSet(long n);
    ~DisjointSet();
    void markUsed(long x);
    void unionBySize(long a, long b);
    long getMaxGroupSize()const{
        return this->largest_size;
    }
    long getLangDeficit()const;
};

long get_id(int lang){
    return long(lang-1);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    DisjointSet lang_set(m);
    long illiterate_cnt = 0;
    for(int i=0; i<n; ++i){
        int k;
        std::cin >> k;
        if(k==0){
            ++illiterate_cnt;
            continue;
        }
        int base_lang;
        std::cin >> base_lang;
        lang_set.markUsed(get_id(base_lang));
        for(int j=1; j<k; ++j){
            int new_lang;
            std::cin >> new_lang;
            lang_set.markUsed(get_id(new_lang));
            lang_set.unionBySize(get_id(base_lang), get_id(new_lang));
        }
    }

    std::cout << lang_set.getLangDeficit() + illiterate_cnt;
    return 0;
}



DisjointSet::DisjointSet(long n){
    this->isused = new bool[n];
    this->parent = new long[n];
    this->size = new long[n];
    for(long i=0; i<n; i++){
        this->isused[i] = false;
        this->parent[i] = i;
        this->size[i] = 1;
    }
    this->n = n;
    this->largest_size = 1;
    this->group_cnt = n;
}

DisjointSet::~DisjointSet(){
    delete[] this->isused;
    delete[] this->parent;
    delete[] this->size;
}

long DisjointSet::getRoot(long idx){
    long root = idx;
    while(this->parent[root] != root){
        root = this->parent[root];
    }
    // path compression
    while(this->parent[idx] != root){
        long temp = this->parent[idx];
        this->parent[idx] = root;
        idx = temp;
    }
    return root;
}

void DisjointSet::markUsed(long x){
    this->isused[x] = true;
}

void DisjointSet::unionBySize(long a, long b){
    // union by size
    long root_a = this->getRoot(a);
    long root_b = this->getRoot(b);
    if(root_a == root_b){
        return;
    }
    long root_small = (this->size[root_a] < this->size[root_b]) ? root_a : root_b;
    long root_big = (this->size[root_a] < this->size[root_b]) ? root_b : root_a;
    this->parent[root_small] = root_big;
    this->size[root_big] += this->size[root_small];
    if(this->size[root_big] > this->largest_size){
        this->largest_size = this->size[root_big];
    }
    --(this->group_cnt);
}

long DisjointSet::getLangDeficit()const{
    long result = this->group_cnt;
    for(long i=0; i<n; ++i){
        if(this->isused[i]==false){--result;}
    }
    return (result==0)?0:(result-1);
}