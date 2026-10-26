class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_pf = 0;
        int min_buy = prices[0];
        for(int i = 1; i< n; i++){
            max_pf = max(prices[i]-min_buy, max_pf);
            min_buy = min(min_buy, prices[i]);
        }
        return max_pf;
    }
};
