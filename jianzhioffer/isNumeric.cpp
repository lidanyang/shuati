//
// Created by LENOVO on 2019/10/7.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    bool isNumeric(char* str)
    {
        int change[8][8] = {
                {1,1,3,2,5,8,8,8},
                {8,8,3,2,5,8,8,8},
                {8,8,2,2,7,4,9,8},
                {8,8,3,8,5,8,9,8},
                {6,6,8,5,8,8,8,8},
                {8,8,5,5,8,8,9,8},
                {8,8,8,5,8,8,8,8},
                {8,8,7,7,8,4,9,8}
        };
        map<char, int> dic;//字符和数组下标的映射关系
        dic['+'] = 0;
        dic['-'] = 1;
        dic['0'] = 2;
        dic['1'] = 3;
        dic['2'] = 3;
        dic['3'] = 3;
        dic['4'] = 3;
        dic['5'] = 3;
        dic['6'] = 3;
        dic['7'] = 3;
        dic['8'] = 3;
        dic['9'] = 3;
        dic['.'] = 4;
        dic['E'] = 5;
        dic['\0'] = 6;
        int sz = strlen(str);
        int state = 0;
        cout << state ;
        for(int i = 0; i <= sz; i++){
            if(str[i] == 'e'){
                str[i] = 'E';
            }
            auto it = dic.find(str[i]);
            if(it != dic.end()){
                state = change[state][it->second];
            }
            else{
                state = change[state][7];
            }
            cout << "-->" << state;
            if(state == 8) {
                cout << endl;
                return false;
            }
            else if(state == 9) {
                cout << endl;
                return true;
            }
        }

    }

};
//+100
//0-->1-->2-->2-->2-->7
//1
//5e2
//0-->2-->4-->5-->7
//1
//-123
//0-->1-->2-->2-->2-->7
//1
//3.1416
//0-->2-->5-->5-->5-->5-->5-->7
//1
//-1E-16
//0-->1-->2-->4-->6-->5-->5-->7
//1
//12e
//0-->2-->2-->4-->8
//0
//1a3.14
//0-->2-->8
//0
//1.2.3
//0-->2-->5-->5-->8
//0
//+-5
//0-->1-->8
//0
//12e+4.3
//0-->2-->2-->4-->6-->5-->8
//0
int main(){
    Solution s;
    char str[100] ={ 0 };
    while(scanf("%s", str) != EOF){
        cout << s.isNumeric(str) << endl;
    }
    return 0;
}
//"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。