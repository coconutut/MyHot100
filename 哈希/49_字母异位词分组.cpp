#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//排序单词为键、单词为值
int main(){
    vector<string> strs({"abc", "acb", "hgh", "ghh", "dop"});
    unordered_map<string, vector<string>> hashtable;
    vector<vector<string>> ans;
    for(string& str : strs){
        string temp = str;
        sort(str.begin(), str.end());
        hashtable[str].push_back(temp);
    }
    for(auto it = hashtable.begin(); it != hashtable.end(); it++){
        ans.push_back(it->second);
    }
    for(vector<string>& x : ans){
        for(string& y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}