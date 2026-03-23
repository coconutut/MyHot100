#include <iostream>
#include <vector>
using namespace std;

//移动零(X) -> 移动非零
int main(){
    vector<int> nums({0, 666666, 0, 8888, 2});
    int ptr = 0;
    for(size_t i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            swap(nums[i], nums[ptr]);
            ptr++;
        }
    }
    for(int x : nums) cout << x << " ";
    return 0;
}