#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

//寻找连续序列左侧入口 unordered_set实现o(1)查询
int main(){
    vector<int> nums({1,0,1,2});
    unordered_set<int> hashList;
    int ans = 1;
    for(int num : nums){
        hashList.insert(num);
    }
    for(auto it = hashList.begin(); it != hashList.end(); it++){
        if(hashList.find(*it - 1) != hashList.end()) continue;
        int temp_ans = 1;
        int temp_num = *it;
        while(hashList.find(temp_num + 1) != hashList.end()){
            temp_ans++;
            temp_num++;
        }
        ans = max(ans, temp_ans);
    }
    cout << ans << endl;
    return 0;
}