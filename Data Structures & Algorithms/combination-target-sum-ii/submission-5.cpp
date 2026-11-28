class Solution {
public:
    void dfs(vector<int>& candidates, int idx, vector<vector<int>>& res, vector<int> subset, int sum , int& target){
        if (sum == target){
            res.push_back(subset);
            return;
        }

        for(int i = idx; i< candidates.size(); i++){
            if (i > idx && candidates[i] == candidates[i-1]){
                continue;
            }
            if(sum + candidates[i] > target){
                break;
            }
            // chose
            subset.push_back(candidates[i]);
            dfs(candidates, i + 1, res, subset, sum+ candidates[i], target);
            subset.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, res, subset, 0 , target);
        return res;
    }
};
