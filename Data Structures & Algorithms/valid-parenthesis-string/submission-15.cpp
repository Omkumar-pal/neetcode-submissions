class Solution {
   public:
    bool solve(vector<vector<int>>&dp, string& s, int idx, int count) {
        if (count < 0) return false;
        if (idx == s.size()) return count == 0;
        if (dp[idx][count] != -1){
            return dp[idx][count];
        }
        int res = 1;
        if (s[idx] == '(') {
            res = solve(dp, s, idx + 1, count + 1);
        } else if (s[idx] == ')') {
            res = solve(dp, s, idx + 1, count - 1);
        }else {
            res = solve(dp, s, idx + 1, count - 1) || solve(dp, s, idx + 1, count + 1) || solve(dp, s, idx + 1, count);
        }
        
        return dp[idx][count] = res;
    }
    bool checkValidString(string s) { 
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(dp,s, 0, 0); }
};
