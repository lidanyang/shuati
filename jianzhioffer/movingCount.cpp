//
// Created by LENOVO on 2019/10/7.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
public:
    int count(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int BFS(int r, int c, int k){
        int res = 0;
        queue<pair<int, int>> q;
        vector<vector<int> > visited(r, vector<int>(c,0));
        visited[0][0] = 1;
        q.push(make_pair(0,0));
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            if(count(cur.first) + count(cur.second) <= k) {
                res++;
                if(cur.first + 1 <= r - 1 && !visited[cur.first + 1][cur.second]){
                    q.push(make_pair(cur.first + 1, cur.second));
                    visited[cur.first + 1][cur.second] = 1;
                }
                if(cur.second + 1 <= c - 1 && !visited[cur.first][cur.second + 1]){
                    q.push(make_pair(cur.first, cur.second + 1));
                    visited[cur.first][cur.second + 1] = 1;
                }
            }
        }
        return res;
    }
    int movingCount(int threshold, int rows, int cols)
    {
        int res = 0;
//        int bound = min(getbound(threshold + 1) - 1, rows - 1);
//        for(int i = 0; i <= bound; i++){
//            int tmp = min(getbound(threshold - count(i) + 1) - 1, cols - 1) + 1;
//            res += tmp;
//            cout << i << " " << tmp - 1 << endl;
//        }
//        res = 0;
//        for(int i = 0; i < rows; i++){
//            for (int j = 0; j < cols; ++j) {
//                if(count(i) + count(j) <= threshold){
//                    res++;
//                    cout << j  << " ";
//                }
//            }
//            cout << endl;
//        }
//        return res;
        return BFS(rows, cols, threshold);
    }
};
int main(){
    Solution s;
    cout << s.movingCount(11,100,30) << endl;
    return 0;
}