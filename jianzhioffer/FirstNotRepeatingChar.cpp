//
// Created by LENOVO on 2019/10/5.
//
#include <iostream>
#include <map>

using namespace std;
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> mp;
        for(int i = 0; i < str.size(); ++i)
            mp[str[i]]++;
        for(int i = 0; i < str.size(); ++i){
            if(mp[str[i]]==1)
                return i;
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout << s.FirstNotRepeatingChar("asdfasfcca");
    return 0;
}
