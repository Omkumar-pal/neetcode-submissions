class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_pf = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                
                int profit = (prices[j]-prices[i]);
                max_pf = max(profit, max_pf);
            }
        }
        return max_pf;
    }
};
