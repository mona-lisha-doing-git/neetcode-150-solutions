#include<iostream>
using namespace std;

class MinStack {
public:

    stack<int> st;
    stack<int> minSt;

    MinStack() {
        
    }
    
    void push(int val) {

        if(!minSt.empty() and val > minSt.top()){
            minSt.push(minSt.top());
        }else minSt.push(val);

        st.push(val);
    }
    
    void pop() {

        st.pop();
        minSt.pop();

    }
    
    int top() {

        return st.top();

    }
    
    int getMin() {

        return minSt.top();
        
    }
};

int main(){
    MinStack ms;

    ms.push(1);
    ms.push(2);
    ms.push(0);

    cout<<ms.getMin()<<endl;

    ms.pop();

    cout<<ms.top()<<endl;
    cout<<ms.getMin()<<endl;

    return 0;
}