#include<iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st1;
        vector<int> nextSmaller(n, n);

        for(int i = n-1; i >= 0; i--){
            while(!st1.empty() and heights[st1.top()] >= heights[i]){
                st1.pop();
            }
            if(!st1.empty()) nextSmaller[i] = st1.top();
            st1.push(i);
        }

        vector<int> prevSmaller(n, -1);
        stack<int> st2;

        for(int i = 0; i < n; i++){
            while(!st2.empty() and heights[st2.top()] >= heights[i]){
                st2.pop();
            }
            if(!st2.empty()) prevSmaller[i] = st2.top();
            st2.push(i);
        }

        int res = 0;
        for(int i = 0; i < n; i++){
           int h = heights[i];
           res = max(res, h * (nextSmaller[i] - prevSmaller[i] - 1));
        }

        return res;
    }
};

int main(){
    Solution sol;

    vector<int> heights = {7,1,7,2,2,4};

    cout<<sol.largestRectangleArea(heights)<<endl;

    return 0;
}