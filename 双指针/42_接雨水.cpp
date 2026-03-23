#include <iostream>
#include <vector>
using namespace std;

//当前位置能接的水 = min(左边最高, 右边最高) - 当前高度
int main(){
    vector<int> heights({4,2,0,3,2,5});
    size_t size = heights.size();
    int left = 0, right = size - 1;
    int leftMax = 0, rightMax = 0;
    int ans = 0;

    while(left < right){
        leftMax = max(leftMax, heights[left]);
        rightMax = max(rightMax, heights[right]);
        if(leftMax < rightMax){
            ans += leftMax - heights[left];
            left++;
        }
        else{
            ans += rightMax - heights[right];
            right--;
        }
    }
    cout << ans << endl;
    return 0;
}