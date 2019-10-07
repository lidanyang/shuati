//
// Created by LENOVO on 2019/10/5.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
private:
    static int record;
    int countn(int n){
        int sum = 0;
        while(n){
            sum += (n % 10 == 1);
            n /= 10;
        }
        return sum;
    }
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int mul = 1;
        int count = 0;
        while(mul <= n){
            count += mul * (n / (10 * mul));
            count += min(mul, max((n % (10 * mul)) - mul + 1, 0));
            mul *= 10;
        }
        return count;
    }
    int NumberOf1Between1AndN_Solution1(int n){
        int sum = 0;
        sum = record + countn(n);
        record = sum;
        return sum;
    }
};

int Solution::record = 1;

int main(){
    Solution s;
    int input = 100;
    for(int i = 10; i < 100000; i++){
        int res = s.NumberOf1Between1AndN_Solution(i);
        int res1 = s.NumberOf1Between1AndN_Solution1(i);
//        std::cout << res << " "<< res1 << std::endl;
        if(res != res1){
            cout << "false" << endl;
            return 1;
        }
    }

    return 0;
}