#include <iostream>
#include <vector>
using namespace std;

//每个格子为到达该格子的方法数，递推到右下角格子（注意边界处理）
int main(){
    int m, n;
    if(!(cin >> m >> n)) return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = (i-1 >= 0 ? dp[i-1][j] : 0) + (j-1 >= 0 ? dp[i][j-1] : 0);
        }
    }
    cout << dp[m-1][n-1] << endl;
    return 0;
}