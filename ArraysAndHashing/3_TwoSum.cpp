#include<iostream>
using namespace std;

/* SOLUTION */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            int rq = target - nums[i];
            if(mp.count(rq)){
                return {mp[rq],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    Solution sol;

    vector<int> nums = {3,4,5,6};
    int target = 7;

    vector<int> answer = sol.twoSum(nums, target);
    for(int& a:answer){
        cout<<a<<" ";
    }cout<<endl;

    return 0;
}