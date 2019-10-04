//
// Created by LENOVO on 2019/10/4.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count = 1;
        int sz = numbers.size();
        if(sz == 0)
            return 0;
        if(sz == 1)
            return numbers[0];
        int cur = numbers[0];
        for(int i = 1; i < sz; i++){
            if(count == 0){
                cur = numbers[i];
                count = 1;
                continue;
            }
            if(numbers[i] == cur) count++;
            else count--;
        }
        if(count == 0) return 0;
        count = 0;
        for(int i = 0; i < sz; i++){
            if(cur == numbers[i])
                count++;
        }
        if(count > sz / 2)
            return cur;
        else
            return 0;
    }
};

int main(){
    auto s = new Solution();
    int res = s->MoreThanHalfNum_Solution(vector<int>({1,2,3,2,4,2,5,2,3}));
    cout << res <<endl;
    return 0;
}