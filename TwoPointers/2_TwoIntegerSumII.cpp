#include<iostream>
using namespace std;

/* SOLUTION */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while(i < j){
            if(nums[i] + nums[j] > target){
                j--;
            }else if(nums[i] + nums[j] < target){
                i++;
            }else return {i+1, j+1};
        }
        return {-1,-1};
    }
};

int main(){
    Solution sol;

    vector<int> numbers = {1,2,3,4};
    int target = 3;

    cout<<sol.twoSum(numbers, target)[0]<<" "<<sol.twoSum(numbers, target)[1]<<endl;

    return 0;
}