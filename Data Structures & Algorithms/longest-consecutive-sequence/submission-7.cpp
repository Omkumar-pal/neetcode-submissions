class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0)return 0;
        int res = 1;
        int streak = 1;
        for(int i = 1; i< nums.size(); i++){
            if (nums[i] == nums[i-1] + 1){ // if valide +1 incr
                streak++;
                res = max(streak, res);
            }else if (nums[i] == nums[i-1]){ // if duplicate
                continue;
            }else { // if any gap
                streak = 1;
            }
        }
        return res;
    }
};
