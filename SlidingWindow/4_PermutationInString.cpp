#include<iostream>
using namespace std;

/* SOLUTION */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int matches = 0;
        int m = s1.size();
        int n = s2.size();
        if(n < m) return false;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(char& c:s1) mp1[c]++;
        for(int i = 0; i < m; i++){
            mp2[s2[i]]++;
        }
        for(char a = 'a'; a <= 'z'; a++){
            if(mp1[a] == mp2[a]) matches++;
        }
        if(matches == 26) return true;
        int i = 0;
        while(i < n-m){
            if(mp1[s2[i]] == mp2[s2[i]]) matches--;
            mp2[s2[i]]--;
            if(mp1[s2[i]] == mp2[s2[i]]) matches++;
            int j = i+m;
            if(j < n){
                bool flag = false;
                if(mp1[s2[j]] != mp2[s2[j]]) flag = true;
                mp2[s2[j]]++;
                if(mp1[s2[j]] == mp2[s2[j]]) matches++;
                else if(!flag) matches--;
            }
            if(matches == 26) return true;
            i++;
        }
        return false;
    }
};

int main(){
    string s1 = "abc", s2 = "lecabee";

    Solution sol;
    
    sol.checkInclusion(s1, s2)? cout<<"true"<<endl : cout<<"false"<<endl;

    return 0;
}