//### [719\. Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)
//
//Difficulty: **Hard**
//
//
//        Given an integer array, return the k-th smallest **distance** among all the pairs. The distance of a pair (A, B) is defined as the absolute difference between A and B.
//
//**Example 1:**
//
//```
//Input:
//nums = [1,3,1]
//k = 1
//Output: 0
//Explanation:
//Here are all the pairs:
//(1,3) -> 2
//(1,1) -> 0
//(3,1) -> 2
//Then the 1st smallest distance pair is (1,1), and its distance is 0.
//```
//
//**Note:**
//
//1.  `2 <= len(nums) <= 10000`.
//2.  `0 <= nums[i] < 1000000`.
//3.  `1 <= k <= len(nums) * (len(nums) - 1) / 2`.
//
//
//#### Solution
//
//        Language: **C++**
//
//```c++
//class Solution {
//public:
//       int countpairs(vector<int>& nums, int k){
//               int sz = nums.size();
//               int count = 0;
//               for(int i = 0; i < sz; i++){
//                       auto a = upper_bound(nums.begin(), nums.end(), nums[i] + k);
//                       count += (a - (nums.begin() + i));
//                   }
//               return count;
//           }
//       int smallestDistancePair(vector<int>& nums, int k) {
//               sort(nums.begin(), nums.end());
//               int sz = nums.size();
//               vector<int> v;
//               int low = 0, high = nums[sz - 1] - nums[0];
//               while(low < high){
//                       int mid = (low + high) >> 1;
//                       int tmp = countpairs(nums, mid);
//                       if(tmp < k)
//                           low = mid + 1, k = k - tmp;
//                       else if(tmp > k)
//                           high = mid;
//                       else
//                           return mid;
//                   }
//               return high;
//               
//               
//           }
//};
//​
//```
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countpairs(vector<int>& nums, int k){
        int sz = nums.size();
        int count = 0;
        for(int i = 0; i < sz; i++){
            auto a = upper_bound(nums.begin(), nums.end(), nums[i] + k);
            count += (a - (nums.begin() + i) - 1);
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector<int> v;
        int low = 0, high = nums[sz - 1] - nums[0];
        cout << low << high << '\n';
        while(low < high){
            int mid = (low + high) >> 1;
            int tmp = countpairs(nums, mid);
            cout << low << " " << high << " " << mid << " " << tmp << '\n';
            if(tmp < k)
                low = mid + 1;
            else if(tmp >= k)
                high = mid;
        }
//        int res = INT_MIN;
//        for(int i = 0; i < sz; i++){
//            auto a = upper_bound(nums.begin(), nums.end(), high);
//            if(a != nums.end()) res = max(res, *a);
//            else res = max(res, *(nums.end() - 1));
//        }
        return high;
    }
};

int main(){
    Solution s;
    vector<int> v{62,100,4};
    cout << s.smallestDistancePair(v, 2);
    return 0;
}