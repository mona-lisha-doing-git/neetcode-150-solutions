#include<iostream>
#include<unordered_set>
using namespace std;

/* SOLUTION */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int maxSubstr = 0;
        int j = 0;
        unordered_set<int> st;
        while(j < n){
            while(st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            maxSubstr = max(maxSubstr, j-i+1);
            j++;
        }
        return maxSubstr;
    }
};

int main(){
    string s = "zxyzxyz";

    Solution sol;

    cout<<sol.lengthOfLongestSubstring(s)<<endl;

    return 0;
}