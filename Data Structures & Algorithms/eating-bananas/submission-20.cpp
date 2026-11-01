class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int mx_pile = piles[piles.size()-1];

        int l = 1;
        int r = mx_pile;
        int ans = INT_MAX;
        while(l <=  r){
            int k = l + (r-l)/2;
            long long total_hrs = 0;
            for(int i = 0; i < piles.size(); i++){
                total_hrs += ceil((double) piles[i]/k);
            }
            if (total_hrs <= h){
                ans = k;
                r = k-1;
            }else {
                l = k + 1;
            }
        }

        return ans;
    }
};
