#include<iostream>
#include<unordered_set>
using namespace std;

/* SOLUTION */
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int& i:nums){
            if(st.count(i)) return true;
            st.insert(i);
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,3};
    bool answer = s.hasDuplicate(nums);

    answer? cout<<"true"<<endl : cout<<"false"<<endl;

    return 0;
}

/* Explanations */
/*
unordered_set is a container from the C++ STL that stores unique elements. 
(It is implemented internally using a hash table. 
A hash table (or hash map) is a data structure that stores data in key-value pairs, 
allowing for extremely fast insertion, lookup, and deletion—typically in constant time, O(1) Time Complexity. )

Important Properties of unordered_set:
Stores only unique values
Elements are not stored in sorted order
Provides very fast operations on average:
Insert → O(1)
Search → O(1)
Delete → O(1)
*/