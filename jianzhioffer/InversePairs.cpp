//
// Created by LENOVO on 2019/10/6.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int count(int l, int r, vector<int> &assist, vector<int>& data){
        if(r == l) return 0;
        int m = (l + r) >> 1;
        int c = (count(l, m, assist, data) + count(m + 1, r, assist, data)) % 1000000007;

        int i = l, j = m + 1, k = l;
        while(i <= m || j <= r){
            if(j > r || (i <= m && data[i] < data[j])){
                c += j - m - 1;
                assist[k++] = data[i++];
            }
            else{
//                c += (m - i + 1);
                assist[k++] = data[j++];
            }
        }
        for(int i = l; i <= r; i++) data[i] = assist[i];
        return c % 1000000007;
    }
    int InversePairs(vector<int> data) {
        vector<int> assist(data);
        return count(0, data.size() - 1, assist, data);
    }
};

int main(){
    Solution s;
    cout << s.InversePairs({364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575}) << endl;
    return 0;
}