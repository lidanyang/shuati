//
// Created by LENOVO on 2019/10/5.
//
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7) return index;
        vector<int> u(index);
        u[0] = 1;

        int t1 = 0, t2 = 0, t3 = 0;
        for(int i = 1; i < index; i++){
            u[i] = min(u[t1] * 2, min(u[t2] * 3, u[t3] * 5));
            if(u[i] == u[t1] * 2) t1++;
            if(u[i] == u[t2] * 3) t2++;
            if(u[i] == u[t3] * 5) t3++;
        }
        return u[index - 1];
    }
};

int main(){
    Solution s;
    cout << s.GetUglyNumber_Solution(1000) << endl;
    return 0;
}
