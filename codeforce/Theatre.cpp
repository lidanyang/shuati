//
// Created by LENOVO on 2019/10/7.
//
#include <iostream>

using namespace std;

int main(){
    __int64 n, m, a, x, y;
    while(cin >> n >> m >> a){
        if(m % a == 0)
            x = m / a;
        else
            x = m / a + 1;
        if(n % a == 0)
            y = n / a;
        else
            y = n / a + 1;
        cout << x * y << endl;
    }
    return 0;
}
