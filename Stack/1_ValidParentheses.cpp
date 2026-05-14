#include<iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char& c:s){

            if(c == '[' || c == '{' || c == '(') st.push(c);
            
            else{
                if(st.empty()) return false;
                if(st.top() == '[' and c == ']'
                or st.top() == '{' and c == '}'
                or st.top() == '(' and c == ')') st.pop();
                else return false;
            }

        }
        
        return st.empty();
    }
};

int main(){
    Solution sol;

    string s = "([{}])";

    sol.isValid(s)? cout<<"true"<<endl : cout<<"false"<<endl;

    return 0;
}