#include<iostream>
using namespace std;

/* SOLUTION */
class Solution {
public:

    string encode(vector<string>& strs) {
        string text;
        for(string& s:strs){
            text += s + '#' + to_string(s.size());
        }
        return text;
    }

    vector<string> decode(string s) {
        vector<string> text;
        int n = s.size();
        if(n == 0) return {};
        int i = n-1;
        while(i >= 0){
            int size = 0;
            string temp;
            while(i >= 0 and s[i] != '#'){
                temp += s[i--];
            }
            i--;
            reverse(temp.begin(), temp.end());
            size = stoi(temp);
            temp = "";
            while(size--){
                temp += s[i--];
            }
            reverse(temp.begin(), temp.end());
            text.push_back(temp);
        }
        reverse(text.begin(), text.end());
        return text;
    }
};

int main(){
    Solution sol;

    vector<string> dummy = {"Hello","World"};

    string s = sol.encode(dummy);
    cout<<s<<endl;

    vector<string> v = sol.decode(s);
    for(string& str:v) cout<<str<<" ";
    cout<<endl;

    return 0;
}