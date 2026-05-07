#include<iostream>
using namespace std;

/* SOLUTION */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1);
        int suff = 1;
        for(int i = 1; i < n; i++){
            pref[i] = pref[i-1] * nums[i-1];
        }
        for(int i = n-2; i >= 0; i--){
            suff *= nums[i+1];
            pref[i] *= suff;
        }
        return pref;

    }
};


int main(){
    Solution sol;

    vector<int> nums = {1,2,4,6};

    vector<int> answer = sol.productExceptSelf(nums);

    for(int& a:answer) cout<<a<<" ";
    cout<<endl;

    return 0;
}