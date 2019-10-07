//
// Created by LENOVO on 2019/10/6.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        vector<bool> child(n, 0);
        if(0 == n) return -1;
        if(0 == m) return -1;
        int count = 0;
        int cur = 0;
        while(count < n){
            int tick = m;
            while(child[cur] || --tick){
                cur = (cur + 1) % n;
            }
            child[cur] = true;
            cur = (cur + 1) % n;
            count++;
        }
        cur = (cur - 1) % n;
        return cur;
    }
};

int main(){
    Solution s;
    cout << s.LastRemaining_Solution(5,3);
    return 0;
}
