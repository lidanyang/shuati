//
// Created by LENOVO on 2019/10/6.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        sort(numbers.begin(), numbers.end());
        int sz = numbers.size();
        int count = 0;
        int i = 0;
        while(numbers[i] == 0) i++;
        int k = i;
        for(i++; i < sz; i++){
            count += numbers[i] - numbers[i - 1] - 1;
        }
        if(count > k)
            return false;
        else
            return true;
    }
};
int main(){
    Solution s;
    cout << s.IsContinuous({0,0,0,0,4});
    return 0;
}