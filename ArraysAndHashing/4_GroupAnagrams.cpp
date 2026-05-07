#include<iostream>
using namespace std;

/* SOLUTION */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(string& s:strs){
            string s1 = s;
            sort(s1.begin(), s1.end());
            mp[s1].push_back(s);
        }
        for(auto& it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};


int main(){
    Solution sol;

    vector<string> strs = {"act","pots","tops","cat","stop","hat"};
    
    vector<vector<string>> answer = sol.groupAnagrams(strs);

    for(vector<string>& ans:answer){
        for(string& a:ans) cout<<a<<" ";
        cout<<endl;
    }

    return 0;
}