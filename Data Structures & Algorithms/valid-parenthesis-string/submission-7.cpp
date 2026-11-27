class Solution {
   public:
    bool solve(string& s, int idx, int count) {
        if (count < 0) return false;
        if (idx == s.size()) return count == 0;
        if (s[idx] == '(') {
            return solve(s, idx + 1, count + 1);
        } else if (s[idx] == ')') {
            return solve(s, idx + 1, count - 1);
        }
        return solve(s, idx + 1, count - 1) || solve(s, idx + 1, count + 1) || solve(s, idx + 1, count);
    }
    bool checkValidString(string s) { return solve(s, 0, 0); }
};
