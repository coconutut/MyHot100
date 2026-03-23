#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//右边进，重复了左边出，unordered_set窗口始终保持无重复
// int main(){
//     string s("abcbcaa");
//     unordered_set<int> windows;
//     int left = 0, ans = 0;
//     for(int right = 0; right < (int)s.size(); right++){
//         while(windows.count(s[right])){
//             windows.erase(s[left]);
//             ++left;
//         }
//         windows.insert(s[right]);
//         ans = max(ans, right - left + 1);
//     }
//     cout << ans << endl;
//     return 0;
// }

//哈希表记录字符上次出现位置
int main(){
    string s("abcbcbcacab");
    unordered_map<char, int> last;
    int left = 0, ans = 0;
    for(int right = 0; right < (int)s.size(); right++){
        if(last.count(s[right])){
            left = max(left, last[s[right]] + 1); //left不能后退，不同字母的last位置不同
        }
        last[s[right]] = right;
        ans = max(ans, right - left + 1);
    }
    cout << ans << endl;
    return 0;
}