#include <iostream>
#include <string>
#include <vector>
using namespace std;

//经典滑动窗口做法，滑动窗口统计数量与原子串的数量比对
int main(){
    string line1;
    getline(cin, line1);
    string line2;
    getline(cin, line2);
    vector<int> counts(26, 0);
    vector<int> windowCounts(26, 0);
    vector<int> ans;
    //先统计line2
    for(char c : line2){
        counts[c-'a']++;
    }
    int window_size = line2.size();
    int left = 0;
    int right = window_size - 1;
    while(right < (int)line1.size()){
        for(int i = left; i <= right; i++){
            windowCounts[line1[i] - 'a']++;
        }
        bool flag = true;
        for(int i = 0; i < 26; i++){
            if(counts[i] != windowCounts[i]){
                flag = false;
                break;
            }
        }
        if(flag) ans.push_back(left);
        right++;
        left++;
        fill(windowCounts.begin(), windowCounts.end(), 0);
    }
    for(int x : ans){
        cout << x << " ";
    }
    return 0;
}