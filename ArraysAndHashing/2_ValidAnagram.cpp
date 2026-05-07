#include<iostream>
using namespace std;

/* SOLUTION */
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main(){
    Solution sol;

    string s = "racecar", t = "carrace";

    sol.isAnagram(s, t)? cout<<"true\n" : cout<<"false\n";

    return 0;
}