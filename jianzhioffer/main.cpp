#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    void next(string now, vector<string> &v){
        v.push_back(now);
        cout << now << endl;
        int i = now.size() - 1;
        while(i > 0 && now[i] <= now[i - 1]) i--;
        if(i == 0){
            return;
        }
        int j = now.size() - 1;
        while(now[i - 1] >= now[j]) j--;
        swap(now[i - 1], now[j]);
        reverse(now.begin() + i, now.end());
        next(now, v);
    }
public:
    vector<string> Permutation(string str) {
        vector<string> v;
        if(str.empty()) return v;
        sort(str.begin(), str.end());
        next(str, v);
        return v;
    }
};

int main() {
    Solution *s = new Solution();
    vector<string> v = s->Permutation("abc");
    for(auto s: v){
        cout << s << endl;
    }
    return 0;
}