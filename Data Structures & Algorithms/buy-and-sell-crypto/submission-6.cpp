class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_pf = 0;
        int min_buy = prices[0];
        for(int i = 1; i< n; i++){
            int profit = prices[i]-min_buy;
            min_buy = min(min_buy, prices[i]);
            max_pf = max(profit, max_pf);
        }
        return max_pf;
    }
};
