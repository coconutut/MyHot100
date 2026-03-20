#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//dp[i][j] 表示将 word1 的前 i 个字符转换成 word2 的前 j 个字符所需要的最少步数
int main(){
    string word1("wcnmb");
    string word2("wacnm");
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    //初始化
    for(int i = 0; i <= m; i++) dp[i][0] = i;
    for(int j = 0; j <= n; j++) dp[0][j] = j;
    //遍历
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(word1[i] == word2[j]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}