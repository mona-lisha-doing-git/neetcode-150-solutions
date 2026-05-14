#include<iostream>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = speed.size();

        vector<pair<int,int>> vec;
        for(int i = 0; i < n; i++){
            vec.push_back({position[i], speed[i]});
        }

        sort(vec.begin(), vec.end());

        stack<pair<int,int>> st;
        st.push(vec[n-1]);

        for(int i = n-2; i >= 0; i--){

            pair<int,int>& p = st.top();

            float t1 = ((float)target - (float)p.first)/(float)p.second;
            float t2 = ((float)target - (float)vec[i].first)/(float)vec[i].second;

            if(t2 <= t1){
                st.pop();
                st.push(p);
            }else{
                st.push(vec[i]);
            }
            
        }

        return st.size();
    }
};

int main(){
    Solution sol;

    int target = 10;
    vector<int> position = {1,4}, speed = {3,2};

    cout<<sol.carFleet(target, position, speed)<<endl;

    return 0;
}