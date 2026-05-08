#include<iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater = 0;
        int i = 0, j = heights.size()-1;
        while(i < j){
            int h = min(heights[i], heights[j]);
            maxWater = max(maxWater, h * (j-i));
            if(heights[i] > heights[j]) j--;
            else i++;
        }
        return maxWater;
    }
};


int main(){
    vector<int> heights = {1,7,2,5,4,7,3,6};

    Solution sol;
    int ans = sol.maxArea(heights);
    cout<<ans<<endl;

    return 0;
}