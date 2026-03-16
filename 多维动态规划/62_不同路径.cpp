#include <iostream>
#include <vector>
using namespace std;

//每个格子为到达该格子的方法数 TO(mn) SO(n)
//初始化阶段已经处理好了第0行和第0列
//dp[j]还未更新，代表上一行的dp
//dp[j-1]已经更新，代表左侧的dp。
int main(){
    int m, n;
    if(!(cin >> m >> n)) return 0;
    vector<int> dp(n, 1);
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            dp[j] = dp[j] + dp[j-1];
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}