#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<int> st;
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++){
            int curr = temperatures[i];

            while(!st.empty() and temperatures[st.top()] < curr){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            
            st.push(i);
        }

        return ans;
    }
};

int main(){
    Solution sol;

    vector<int> temperatures = {30,38,30,36,35,40,28};

    vector<int> ans = sol.dailyTemperatures(temperatures);
    for(int& t:ans){
        cout<<t<<" ";
    }cout<<endl;

    return 0;
}