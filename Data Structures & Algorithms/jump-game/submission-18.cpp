class Solution {
   public:
    void solve(vector<int>& nums, int idx, bool& ans, vector<bool>& isVisited) {
        if (idx >= nums.size() - 1) {
            ans = true;
            return;
        }
        if (isVisited[idx]) return;

        isVisited[idx] = true;
        int jump = nums[idx];
        for (int i = 1; i <= jump; i++) {
            solve(nums, idx + i, ans, isVisited);
        }
    }
    bool canJump(vector<int>& nums) {
        vector<bool> isVisited(nums.size(), false);
        bool ans = false;
        solve(nums, 0, ans, isVisited);
        return ans;
    }
};
