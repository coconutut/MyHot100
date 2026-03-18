#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Manacher Algorithm
int main(){
    string s;
    cin >> s;
    string T = "^";
    for(char c : s){
        T += "#";
        T += c;
    }
    T += "#$";
    int n = T.length();
    int C = 0;  //最右中心
    int R = 0; //最右边界
    vector<int> P(n, 0);
    for(int i = 1; i < n-1; i++){
        if(i < R){
            P[i] = min(R - i, P[2*C - i]);
        }
        while(T[i - P[i] - 1] == T[i + P[i] + 1]){
            P[i]++;
        }
        if(i + P[i] > R){
            R = i + P[i];
            C = i;
        }
    }
    int maxLen = 0;
    int center = 0;
    for(int i = 0; i < n-1; i++){
        if(P[i] > maxLen){
            center = i;
            maxLen = P[i];
        }
    }
    int start = (center - maxLen) / 2;
    cout << s.substr(start, maxLen) << endl;
    return 0;
}