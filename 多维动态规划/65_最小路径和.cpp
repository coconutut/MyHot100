#include <iostream>
#include <vector>
using namespace std;

//每个格子的状态为到达该格子的最小代价
//原地更新grid表格 TO(mn) SO(1)
int main(){
    vector<vector<int>> grid({{1, 2, 3}, {4, 5, 6}});
    if(grid.size() == 0) return 0;
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i-1 >= 0 && j-1 >= 0){
                grid[i][j] = min(grid[i-1][j] + grid[i][j], grid[i][j-1] + grid[i][j]);
            }else if(i-1 >= 0){
                grid[i][j] = grid[i-1][j] + grid[i][j];
            }else if(j-1 >= 0){
                grid[i][j] = grid[i][j-1] + grid[i][j];
            }
        }
    }
    cout << grid[m-1][n-1] << endl;
    return 0;
}