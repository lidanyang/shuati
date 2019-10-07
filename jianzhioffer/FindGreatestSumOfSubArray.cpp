//
// Created by LENOVO on 2019/10/5.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sz = array.size();
        int cur = array[0];
        int res = INT_MIN;
        for(int i = 1; i < sz; i++){
            res = max(cur, res);
            cur = max(array[i] + cur, array[i]);
        }
        res = max(cur, res);
        return res;
    }
};

int main(){
    Solution s;
    int res = s.FindGreatestSumOfSubArray({2,8,1,5,9});
    cout << res << endl;
    return 0;
}