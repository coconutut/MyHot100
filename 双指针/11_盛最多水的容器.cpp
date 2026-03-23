#include <iostream>
#include <vector>
using namespace std;

//双指针+贪心
int main(){
    int maxNum = 0;
    vector<int> nums({1, 1});
    size_t size = nums.size();
    int head = 0, tail = size - 1;
    while(head < tail){
        if(nums[head] < nums[tail]){
            int temp = (tail - head) * nums[head];
            maxNum = max(maxNum, temp);
            head++;
        }
        else{
            int temp = (tail - head) * nums[tail];
            maxNum = max(maxNum, temp);
            tail--;
        }
    }
    cout << maxNum << endl;
    return 0;
}