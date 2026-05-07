#include<iostream>
using namespace std;

/* SOLUTION */
class Solution {
public:
    bool isValid(char& c){
        return (c >= 'a' and c <= 'z') or (c >= '0' and c <= '9')? true:false;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i < j){
            char c1 = tolower(s[i]);
            char c2 = tolower(s[j]);

            if(!isValid(c1)) i++;
            else if(!isValid(c2)) j--;
            else if(c1 != c2) return false;
            else i++, j--;
        }
        return true;
    }
};

int main(){
    Solution sol;

    string s = "Was it a car or a cat I saw?";

    sol.isPalindrome(s)? cout<<"true"<<endl:cout<<"false"<<endl;

    return 0;
}