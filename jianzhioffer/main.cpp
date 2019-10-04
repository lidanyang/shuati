#include <iostream>
#include <vector>
#include <algorithm>

//输入一个字符串,按字典序打印出该字符串中字符的所有排列。
//例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
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