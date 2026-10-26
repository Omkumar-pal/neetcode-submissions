class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int max_pf = 0;
        while(r < prices.size()){
            if (prices[r] > prices[l]){
                max_pf = max(prices[r]-prices[l], max_pf);
            }else {
                l = r;
            }
            r++;
        }
        return max_pf;
    }
};
