#include <iostream>
#include <vector>
using namespace std;
//LongestCommonSubsequence -> LCS
//dp[i][j]表示前i个text1字符和前j个text2字符的公共子序列长度
int main(){
    string text1("abcdef");
    string text2("aceggg");
    int size1 = text1.size();
    int size2 = text2.size();
    int maxLen = 0;
    vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));
    for(int i = 1; i <= size1; i++){
        for(int j = 1; j <= size2; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    cout << maxLen << endl;
    return 0;
}