class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        int sum = nums[0];
        while(i <  nums.size() && j < nums.size()){
            if (sum >= 0){
                ans = max(sum, ans);
                j++;
                if (j >= nums.size()) continue;
                sum += nums[j];
                ans = max(sum, ans);
            }else {
                ans = max(sum, ans);
                i++;
                j = i;
                if (i >= nums.size()) continue;
                sum = nums[i];
            }
        }

        return ans;
    }
};
