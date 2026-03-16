#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//先查哈希表找答案，没有的话记录当前的记录 To(n) So(n)
int main(){
    int target;
    cin >> target;
    int temp;
    vector<int> nums;
    while (cin >> temp) nums.push_back(temp);
    unordered_map<int, int> hash;
    for(int i = 0; i < nums.size(); i++){
        if(hash.find(target - nums[i]) == hash.end()){
            hash[nums[i]] = i;
        }
        else{
            cout << i << " " << hash[target - nums[i]] << endl;
            break;
        }
    }
    return 0;
}