//
// Created by LENOVO on 2019/10/8.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    priority_queue<int, vector<int>, less<int> > q1; //存放上半部,大顶堆
    priority_queue<int, vector<int>, greater<int> > q2; //存放下半部，小顶堆

    void show(){
        if(q1.size())
            cout << q1.top() << "|";
        if(q2.size())
            cout << q2.top() << endl;
    }
    void Insert(int num)
    {
        if(q1.size() > q2.size()){
            int i = q1.top();
            if(num > i)
                q2.push(num);
            else{
                q1.pop();
                q2.push(i);
                q1.push(num);
            }
        }
        else{
            if(q1.size() == 0){
                q1.push(num);
                return;
            }
            int j = q2.top();
            if(num > j){
                q2.pop();
                q1.push(j);
                q2.push(num);
            }
            else
                q1.push(num);
        }
    }

    double GetMedian()
    {
        if(q1.size() == 0)
            return 0;
        if(q1.size() > q2.size())
            return q1.top();
        return (q1.top() + (double)q2.top()) / 2;
    }

};

int main(){
    Solution s;
    int num;//5,2,3,4,1,6,7,0,8
    while(cin >> num){
        s.Insert(num);
        s.GetMedian();
        s.show();
    }
    return 0;
}
