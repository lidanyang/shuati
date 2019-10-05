//
// Created by LENOVO on 2019/10/4.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int sz = input.size();
        vector<int> v(input.begin(), input.begin() + k);
        make_heap(v.begin(), v.end());
        for(int i = k; i < sz; i++){
            if(input[i] < v[0]){
                v[0] = input[i];
                make_heap(v.begin(), v.end());
            }
        }
        return v;
    }
};

int main(){
    Solution s;
    vector<int> v = s.GetLeastNumbers_Solution({4,5,1,6,2,7,3,8}, 1);
    for(auto s: v){
        cout << s << endl;
    }
    return 0;
}