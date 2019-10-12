//
// Created by LENOVO on 2019/10/10.
//
#include <bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>

using namespace std;

int DFS(vector<int> &v, int start, int end, int w){
    int count = 0;
    if(w < 0)
        return 0;
    if(start > end)
        return 1;
    return DFS(v, start + 1, end, w - v[start]) + DFS(v, start + 1, end, w);

}
int main(){
    int n, w;
    vector<int> v;
    cin >> n >> w;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    int sz = v.size();
    if(sz > 29){
        cout << 0 << endl;
    }
    cout << DFS(v, 0, sz - 1, w) << endl;
    return 0;
}