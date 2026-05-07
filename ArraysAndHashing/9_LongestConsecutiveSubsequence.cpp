#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutiveSubsequence(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int maxLen = 1;
        unordered_set<int> st(nums.begin(), nums.end());

        for(int& num:nums){
            if(st.count(num-1)) continue;
            int curr = num;
            int len = 1;
            while(st.count(curr + 1)){
                len++;
                curr = curr+1;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {2,20,4,10,3,4,5};

    cout<<sol.longestConsecutiveSubsequence(nums)<<endl;

    return 0;
}