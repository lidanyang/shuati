#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

inline void pushup(ll* N, int id){
    N[id] = N[id << 1] + N[id << 1|1];
}

inline void pushdown(ll *N, ll *lazy, int root, int l, int r){
    int m = (l + r) >> 1;
    lazy[root<<1] += lazy[root];
    lazy[root<<1|1] += lazy[root];
    N[root<<1] += lazy[root] * (m - l + 1);
    N[root<<1|1] += lazy[root] * (r - m);
    lazy[root] = 0;
}
//root是线段树的结点的编号，l和r是线段树维护的原始区间的左右端点
void build(ll *N, ll root, ll l, ll r){
    if(l == r){
        cin >> N[root];//叶结点
        return;
    }
    int m = (l + r) >> 1;
    build(N, root<<1, l, m);//左子树
    build(N, root<<1|1, m + 1, r);//右子树
    pushup(N, root);
}

void update(ll N[], ll lazy[], int val, int root, int l, int r, int L, int R){
    if(L == l && r == R){
        lazy[root] += val;
        N[root] += val * (r - l + 1);
        return;
    }
    pushdown(N, lazy, root, l, r);
    int m = (l + r) >> 1;
    if(m < L) update(N, lazy, val, root << 1|1, m + 1, r, L, R);
    else if(m >= R) update(N, lazy, val, root << 1, l, m, L, R);
    else{
        update(N, lazy, val, root << 1|1, m + 1, r, m + 1, R);
        update(N, lazy, val, root << 1, l, m, L, m);
    }
    pushup(N, root);
}

ll query(ll N[], ll lazy[], int root, int l, int r, int L, int R){
    if(l == L && r == R){
        return N[root];
    }
    pushdown(N, lazy, root, l, r);
    int m = (l + r) >> 1;
    if(m < L) return query(N, lazy, root<<1|1, m + 1, r, L, R);
    else if(R <= m) return query(N, lazy,root<<1, l, m, L, R);
    else return query(N, lazy, root<<1|1, m + 1, r, m + 1, R)
                    + query(N, lazy, root<<1, l, m, L, m);
}

int main(){
    ll N, M;
    cin >> N >> M;
    ll *arr = new ll[4*N]();
    ll *marked = new ll[4*N]();
    build(arr, 1, 1, N);
    for(int i = 0; i < M; i++){
        int flag, l, r, val;
        scanf("%d", &flag);
        if(flag == 1){
            scanf("%d %d %d", &l, &r, &val);
            update(arr, marked, val, 1, 1, N, l, r);
        }
        else{
            scanf("%d %d", &l, &r);
            cout << query(arr, marked, 1, 1, N, l, r) << endl;
        }
    }
    return 0;
}
