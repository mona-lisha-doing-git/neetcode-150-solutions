#include<iostream>
#include<set>
using namespace std;

/* SOLUTION*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        set<pair<int,int>> st;
        for(int& num:nums){
            mp[num]++;
        }
        for(auto& [num, freq]:mp){
            st.insert({freq, num});
        }
        vector<int> ans;
        while(k-- && st.size() > 0){
            ans.push_back((*(st.rbegin())).second);
            st.erase(*st.rbegin());
        }
        
        return ans;
    }
};

int main(){
    Solution sol;

    vector<int> nums = {1,2,2,3,3,3};
    int k = 2;

    vector<int> answer = sol.topKFrequent(nums, k);

    for(int& a:answer) cout<<a<<" ";
    cout<<endl;

    return 0;
}