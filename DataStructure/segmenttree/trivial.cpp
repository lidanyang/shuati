#include <iostream>
#define long long ll
#define N 10

using namespace std;

class SegmentTree{
private:
    int stree[N + 1];//维护每个区间结点的一个值，长度为N的区间，需要2N个区间结点
public:
    void build(int l, int r, int root);
    void update(int p, int l, int r, int val, int root);
    int query(int l, int r, int L, int R, int root);
};

void SegmentTree::build(int l, int r, int root) {
    if(l == r){
        stree[root] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, root<<1);
    build(m + 1, r, root<<1|1);
    stree[root] = stree[root<<1] + stree[root<<1|1];
}

void SegmentTree::update(int p, int l, int r, int val, int root) {
    if(l == r){
        stree[root] += val;
        return ;
    }
    int m = (l + r) >> 1;
    if(p <= m) update(p, l, m, val, root<<1);
    else update(p, m + 1, r, val, root<<1|1);
    stree[root] = stree[root<<1] + stree[root<<1|1];
}

int SegmentTree::query(int l, int r, int L, int R, int root) {
    if(L == R){
        return stree[root];
    }
    int M = (L + R) >> 1;
    if(r <= M) return query(l, r, L, M, root<<1);
    else if(l > M) return query(l, r, M + 1, R, root<<1|1);
    else
        return query(l, r, L, M, root<<1) + query(l, r, M + 1, R, root<<1|1);
}

int main(){
    SegmentTree t;
    t.build(1, N, 1);
    int i;
    while(cin >> i){
        int l, r;
        t.update(i,1,N,1,1);
        cout << "left:";
        cin >> l;
        cout << "right:";
        cin >> r;
        cout << t.query(l, r, 1, N, 1) << endl;
    }
    return 0;
}