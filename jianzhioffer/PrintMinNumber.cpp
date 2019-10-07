//
// Created by LENOVO on 2019/10/5.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(const string &s1, const string &s2){
    string str1 = s1 + s2;
    string str2 = s2 + s1;
    int sz = str1.size();
    int i = 0;
    for(; i < sz && str1[i] == str2[i]; i++);
    if(i < sz){
        return str1[i] < str2[i];
    }
}
class Solution{
private:
    vector<string> &tostring(const vector<int> &num){
        string tmp;
        vector<string> *v = new vector<string>();
        for(auto n: num){
            while(n){
                tmp.append(1, '0'+ (n % 10));
                n /= 10;
            }
            reverse(tmp.begin(), tmp.end());
            v->push_back(tmp);
            tmp.erase(0);
        }
        return *v;
    }
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> vs = tostring(numbers);
        sort(vs.begin(), vs.end(), comp);
        string res;
        for(auto s : vs)
            res.append(s);
        return res;
    }
};

int main(){
    Solution s;
    cout << s.PrintMinNumber({3334,3,3333332}) << endl;
    return 0;
}
