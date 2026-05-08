#include<iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int mxWater = 0;
        int mxLeft = 0;
        int mxRight = 0;
        while(l < r){
            if(height[l] <= height[r]){
                mxLeft = max(mxLeft, height[l]);
                mxWater += mxLeft - height[l];;
                l++;
            }else{
                mxRight = max(mxRight, height[r]);
                mxWater += mxRight - height[r];;
                r--;
            }
        }
        return mxWater;
    }
};

int main(){
    vector<int> heights = {0,2,0,3,1,0,1,3,2,1};

    Solution sol;
    int ans = sol.trap(heights);

    cout<<ans<<endl;

    return 0;
}