class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        int sum = nums[0];
        while(i <  nums.size() && j < nums.size()){
            ans = max(sum, ans);
            if (sum >= 0){
                j++;
                if (j >= nums.size()) continue;
                sum += nums[j];
                ans = max(sum, ans);
            }else {
                i++;
                j = i;
                if (i >= nums.size()) continue;
                sum = nums[i];
            }
        }

        return ans;
    }
};
