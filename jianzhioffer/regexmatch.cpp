//
// Created by LENOVO on 2019/10/6.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        int ls = strlen(str), lp = strlen(pattern);
        cout << ls << lp << endl;
        if(lp == 0 && ls == 0) return true;
        vector<vector<bool> > dp(ls + 1,
                                 vector<bool>(lp + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= ls;i++){
            for(int j = 1; j <= lp; j++){
                if(i == 0){
                    dp[0][j] = pattern[j - 1] == '*' && dp[0][j - 2];
                }
                else if(pattern[j - 1] == '*'){
                    dp[i][j] = ((str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.') && dp[i - 1][j])||
                               dp[i][j - 2];
                }
                else if(pattern[j - 1] == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                    dp[i][j] = pattern[j - 1] == str[i - 1] && dp[i - 1][j - 1];
            }
        }
        for(int i = 0; i <= ls; i++){
            for(int j = 0; j <= lp; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[ls][lp];
    }
};

int main(){
    Solution s;
    cout << s.match("a",".*") << endl;
    return 0;
}