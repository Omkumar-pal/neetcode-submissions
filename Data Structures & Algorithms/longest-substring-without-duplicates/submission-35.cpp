class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int l = 0;
        unordered_map<char,int> set;
        for(int r = l; r<s.size(); r++){
            if (set.count(s[r])){
                l = max(l, set[s[r]] + 1);
            }
            set[s[r]] = r;
            res = max(res, r-l+1);
        }
        return res;
    }
};
