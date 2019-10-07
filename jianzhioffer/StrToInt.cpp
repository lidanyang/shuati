//
// Created by LENOVO on 2019/10/6.
//
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        int state = 0;
        int i = 0;
        int base = 0;
        int sign = 1;
        int sum = 0;
        while(state != 6 && str[i] != '\0'){
            if(state == 0){
                if(str[i] == '0'){
                    state = 2;
                }
                else if(str[i] == '+' || str[i] == '-'){
                    state = 1;
                    sign = (str[i] == '+') ? 1 : -1;
                }
                else if(str[i] <= '9' && str[i] >= '1'){
                    state = 3;
                    base = 10;
                    sum = base * sum + str[i] - '0';
                }
                else
                    state = 6;
            }
            else if(state == 1){
                if(str[i] <= '9' && str[i] >= '1'){
                    state = 3;
                    base = 10;
                    sum = base * sum + str[i] - '0';
                }
                else if(str[i] == '0'){
                    state = 2;
                }
                else
                    state = 6;
            }
            else if(state == 2){
                if(str[i] <= '9' && str[i] >= '1'){
                    state = 3;
                    base = 8;
                    sum = base * sum + str[i] - '0';
                }
                else if(str[i] == 'x'){
                    state = 4;
                }
                else
                    state = 6;
            }
            else if(state == 3){
                if(str[i] <= '9' && str[i] >= '0'){
                    state = 3;
                    if((sign == 1 && sum > (INT_MAX + '0' - str[i]) / base )||
                        (sign == -1 && sum > (INT_MAX +  (1 + '0' - str[i])) / base)) return 0;
                    sum = base * sum + str[i] - '0';
                }
                else
                    state = 6;
            }
            else if(state == 4){
                if(str[i] <= '9' && str[i] >= '1' ||
                   str[i] >= 'A' && str[i] <= 'F' ||
                   str[i] >= 'a' && str[i] <= 'f'){
                    state = 5;
                    base = 16;
                    if(str[i] <= '9'){
                        sum = base * sum + str[i] - '0';
                    }
                    else if(str[i] <= 'F'){
                        sum = base * sum + str[i] - 'A' + 10;
                    }
                    else{
                        sum = base * sum + str[i] - 'a' + 10;
                    }
                }
                else
                    state = 6;
            }
            else if(state == 5){
                if(str[i] <= '9' && str[i] >= '0' ||
                   str[i] >= 'A' && str[i] <= 'F' ||
                   str[i] >= 'a' && str[i] <= 'f'){
                    state = 5;
                    if(str[i] <= '9'){
                        sum = base * sum + str[i] - '0';
                    }
                    else if(str[i] <= 'F'){
                        sum = base * sum + str[i] - 'A' + 10;
                    }
                    else{
                        sum = base * sum + str[i] - 'a' + 10;
                    }
                }
                else
                    state = 6;
            }
            i++;
        }
        if(state == 6)
            return 0;
        else
            return sum * sign;
    }
};

int main(){
    Solution s;
    cout << s.StrToInt("-2147483649") << endl;
//    cout << s.StrToInt("+123") << endl;
//    cout << s.StrToInt("-123") << endl;
//    cout << s.StrToInt("0x0123") << endl;
//    cout << s.StrToInt("0xA123") << endl;
//    cout << s.StrToInt("+0xA123") << endl;
//    cout << s.StrToInt("-0xA123") << endl;
//    cout << s.StrToInt("0123") << endl;
//    cout << s.StrToInt("+0123") << endl;
//    cout << s.StrToInt("-0123") << endl;
    return 0;
}