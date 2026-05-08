#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n-2; i++){
            if(i > 0 and nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) j++;
                else if(sum > 0) k--;
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while(j < k and nums[j] == nums[j-1]) j++;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};

    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);

    for(vector<int> &v:ans){
        for(int& i:v) cout<<i<<" ";
        cout<<endl;
    }
    

    return 0;
}