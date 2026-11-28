class Solution {
public:
    void dfs(vector<int>& nums, int idx, vector<int> subset, vector<vector<int>>&res, int sum, int &target){
        
        if (sum == target){
            res.push_back(subset);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            if (sum + nums[i] > target){
                break;
            }
            // chose
            subset.push_back(nums[i]);
            dfs(nums,i,subset, res, sum + nums[i], target);
            subset.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, subset, res, 0, target);
        return res;
    }
};
