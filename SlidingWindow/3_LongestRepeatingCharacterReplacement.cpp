#include<iostream>
using namespace std;

/* SOLUTION */
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char, int> freq;
        int res = 0;

        int f = 0;
        while(j < n){
            freq[s[j]]++;
            f = freq[s[j]] > f? freq[s[j]]:f;
            
            while(i < j and (j-i+1) - f > k){
                freq[s[i]]--;
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};

int main(){
    string s = "XYYX";
    int k = 2;

    Solution sol;

    cout<<sol.characterReplacement(s, k)<<endl;

    return 0;
}