//
// Created by LENOVO on 2019/10/6.
//
//找大小为n的数组重复数，数组中数的取值范围是0~n-1
#include <iostream>
using namespace std;
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        int i = 0;
        for(; i < length; i++){
            int tmp;
            int j = numbers[i];
            while(j != i && numbers[j] != j){
                tmp = numbers[j];
                numbers[j] = j;
                j = tmp;
            }
            if(j == i){
                numbers[i] = j;
            }
            else{
                *duplication = j;
                return true;
            }
        }
        return false;
    }
};
int main(){
    Solution s;
    int res = 0;
    int numbers[7] = {2,3,1,0,2,5,3};
    s.duplicate(numbers, 7, &res);
    cout << res << endl;
    return 0;
}