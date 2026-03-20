#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
//dp[i]表示以nums[i]结尾的递增序列长度
int main(){
    vector<int> nums({1, 2, 3, 5, 1, 2, 3});
    int size = nums.size();
    int maxLen = 0;
    vector<int> dp(size, 1);
    for(int i = 1; i < size; i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
            maxLen = max(maxLen, dp[i]);
        }
    }
    cout << maxLen << endl;
    return 0;
}
*/

//贪心 + 二分查找 tail[i]为长度为i的最小的末尾元素
int main(){
    vector<int> nums({1, 2, 3, 5, 6, 1});
    vector<int> tails;
    for(int x : nums){
        //返回第一个大于等于查找值的迭代器、二分查找（有序序列）
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if(it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    cout << tails.size() << endl;
    return 0;
}