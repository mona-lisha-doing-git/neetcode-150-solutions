#include<iostream>
using namespace std;

/* SOLUTION */
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        for(char& c:t) need[c]++;

        string res;
        int n = s.size(), m = t.size();
        if(m > n) return "";

        int i = 0;
        int len = INT_MAX;
        while(i <= n-m){
            int j = i;
            string curr;
            unordered_map<char, int> have;
            while(j < n){
                curr += s[j];
                have[s[j]]++;
                bool flag = true;
                for(auto &[c,f]:need){
                    if(have[c] < need[c]){
                        flag = false; break;
                    }
                }
                if(flag){
                    if(len > j-i+1){
                        len = j-i+1;
                        res = curr;
                    }
                    break;
                }
                j++;
            }
            i++;
        }
        return res;
    }
};

int main(){
    string s = "OUZODYXAZV", t = "XYZ";

    Solution sol;
    cout<<sol.minWindow(s, t)<<endl;


    return 0;
}