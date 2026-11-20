class Solution {
public:

    int dfs(vector<int>& nums, int idx, vector<int> &isVisited){
        if (idx >= nums.size()-1){
            return 0;
        }
        if (nums[idx] == 0){
            return 100000;
        }
        if (isVisited[idx] != -1){
            return isVisited[idx];
        }
        int res = 100000;
        for(int i = 1 + idx; i<= idx + nums[idx]; i++){
            res = min(res,1 + dfs(nums, i, isVisited));
        }
        isVisited[idx] = res;
        return res;
    }
    int jump(vector<int>& nums) {
        vector<int> isVisited(nums.size(), -1);
        return dfs(nums, 0, isVisited);
    }
};
