//
// Created by LENOVO on 2019/10/7.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool DFS(char *matrix,int rows, int cols,
             int r, int c, char* str, vector<vector<int> > &visited){
        if(str[0] == '\0') return true;
        cout << matrix[cols * r + c] << " " << cols * r + c << " ";
        if(r > rows - 1 || c > cols - 1 || r < 0 || c < 0 ||
           visited[r][c] == 1 || str[0] != matrix[cols * r + c]){
            return false;
        }
        visited[r][c] = 1;
        if(DFS(matrix, rows, cols, r + 1, c, str + 1, visited) ||
           DFS(matrix, rows, cols, r - 1, c, str + 1, visited) ||
           DFS(matrix, rows, cols, r, c + 1, str + 1, visited) ||
           DFS(matrix, rows, cols, r, c - 1, str + 1, visited)){
            return true;
        }
        visited[r][c] = 0;
        return false;

    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        vector<vector<int> > visited(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++){
                if(matrix[cols * i + j] == str[0]){
                    bool status = DFS(matrix, rows, cols, i, j, str, visited);
                    cout << i << "," << j << endl;
                    if(status)
                        return true;
                }
            }
        cout << "unfound!" << endl;
        return false;
    }
};

int main(){
    Solution s;
    s.hasPath("ABCESFCSADEE",3,4,"SEE");
    return 0;
}