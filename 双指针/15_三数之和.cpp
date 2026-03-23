#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

//TO(n2) SO(n) 固定 i + 哈希找两数
// int main(){
//     vector<int> nums({-1,0,1,2,-1,-4});
//     size_t size = nums.size();
//     unordered_set<int> seen;
//     set<vector<int>> ans;
//     for(size_t i = 0; i < size - 2; i++){
//         if(nums[i] > 0) break;
//         int target = -nums[i];
//         for(size_t j = i + 1; j < size; j++){
//             if(seen.find(target - nums[j]) != seen.end()){
//                 vector<int> temp({-target, nums[j], target - nums[j]});
//                 sort(temp.begin(), temp.end());
//                 ans.insert(temp);
//             }
//             seen.insert(nums[j]);
//         }
//         seen.clear();
//     }
//     for(auto v : ans){
//         for(int x : v){
//             cout << x << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//两端指针逼近 + 去重重复值
int main(){
    vector<int> nums({0,0,0});
    vector<vector<int>> ans;
    size_t size = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 0; i < (int)size - 2; i++){
        if(nums[i] > 0) break;
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int left = i + 1;
        int right = size - 1;
        while(left < right){
            if(nums[left] + nums[right] + nums[i] > 0){
                right--;
            }else if(nums[left] + nums[right] + nums[i] < 0){
                left++;
            }else{
                ans.push_back({nums[left], nums[right], nums[i]});
                left++;
                right--;
                //去重
                while(left < right && nums[left] == nums[left-1]) left++;
                while(left < right && nums[right] == nums[right+1]) right--;
            }
        }
    }
    for(auto v : ans){
        for(int i : v) cout << i << " ";
        cout << endl;
    }
}