class Solution {
public:
    void dfs(vector<int>& nums,vector<int>& subset,vector<vector<int>>& res,  int idx){
        if (idx == nums.size()){
            res.push_back(subset);
            subset.pop_back();
            return;
        }

        // including
        subset.push_back(nums[idx]);
        dfs(nums, subset, res, idx + 1);
        // not including 
        dfs(nums, subset, res, idx + 1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        dfs(nums, subset, res, 0);
        return res;
    }
};
