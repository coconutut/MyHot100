#include <iostream>
#include <string>
#include <stack>
using namespace std;

//保存最近一次不合法的位置（注意-1的妙用）
int main(){
    string str;
    cin >> str;
    int n = str.size();
    stack<int> stk;
    stk.push(-1);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(str[i] == '('){
            stk.push(i); 
        }
        else{
            stk.pop();
            if(stk.empty()){
                stk.push(i);
            }
            else{
                ans = max(ans, i - stk.top());
            }   
        }
    }
    cout << ans << endl;
    return 0;
}