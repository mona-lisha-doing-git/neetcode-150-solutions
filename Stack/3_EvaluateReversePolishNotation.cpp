#include<iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(string& t:tokens){

            if(t == "+" || t == "-" || t == "/" || t == "*"){
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                if(t == "+") st.push(to_string(b + a));
                else if(t == "-") st.push(to_string(b - a));
                else if(t == "/") st.push(to_string(b / a));
                else st.push(to_string(b * a));
            }else{
                st.push(t);
            }

        }

        return stoi(st.top());
    }
};

int main(){
    Solution sol;

    vector<string> tokens = {"2","1","+","3","*"};

    int ans = sol.evalRPN(tokens);

    cout<<ans<<endl;

    return 0;
}