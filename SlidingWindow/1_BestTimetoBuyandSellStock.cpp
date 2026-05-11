#include<iostream>
using namespace std;

/* SOLUTION */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMinPrice = INT_MAX;
        int profit = 0;
        for(int& p:prices){
            currMinPrice = min(currMinPrice, p);
            profit = max(profit, p - currMinPrice);
        }
        return profit;
    }
};

int main(){
    vector<int> prices = {10,1,5,6,7,1};
    Solution sol;

    cout<<sol.maxProfit(prices)<<endl;

    return 0;
}