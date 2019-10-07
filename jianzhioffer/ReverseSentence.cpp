//
// Created by LENOVO on 2019/10/6.
//

#include <sstream>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        int sz = str.size();
        cout << str << endl;
        if(0 == sz) return str;
        int s = 0, e = 0;
        while(s < sz){
            while(s < sz && str[s] == ' '){
                s++;
            }
            e = s;
            while(e < sz && str[e] != ' '){
                e++;
            }
            reverse(str.begin() + s, str.begin() + e);
            s = e;
        }
        return str;
    }
};
int main(){
    Solution s;
    cout << s.ReverseSentence(" student. a am I ") << "ss";
    return 0;
}