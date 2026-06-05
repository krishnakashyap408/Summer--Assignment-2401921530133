class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit1=0;
        int mini=prices[0];
        for(int sell=1;sell<prices.size();sell++){
            int profit2=0;
            profit2=prices[sell]-mini;
            profit1=max(profit2,profit1);
            mini=min(mini,prices[sell]);
        }
        return profit1;
    }
};