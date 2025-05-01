// LEETCODE 121 --> O(n)

#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = prices[0];
        int sell = prices[0];

        int max_profit = 0;
        
        for(int i=0; i<prices.size(); i++){

            if(prices[i] < buy){

                max_profit = max(max_profit, sell-buy);

                buy = prices[i];
                sell = prices[i];
            }

            else sell = max(prices[i], sell);
        }

        max_profit = max(max_profit, sell-buy);

        return max_profit;
    }
};