#include <iostream>
#include <vector>
using namespace std;

//每个格子的状态为到达该格子的最小代价，递推找到右下角格子（注意边界处理）
int main(){
    vector<vector<int>> grid({{1, 2, 3}, {4, 5, 6}});
    if(grid.size() == 0) return 0;
    int m = grid.size();
    int n = grid[0].size();
    auto dp(grid);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i-1 >= 0 && j-1 >= 0){
                dp[i][j] = min(dp[i-1][j] + dp[i][j], dp[i][j-1] + dp[i][j]);
            }else if(i-1 >= 0){
                dp[i][j] = dp[i-1][j] + dp[i][j];
            }else if(j-1 >= 0){
                dp[i][j] = dp[i][j-1] + dp[i][j];
            }
        }
    }
    cout << dp[m-1][n-1] << endl;
    return 0;
}