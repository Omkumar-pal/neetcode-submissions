class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int l = 0;
        unordered_set<char> set;
        for(int r = l; r< s.size(); r++){
            while(set.count(s[r])){
                set.erase(s[l]);
                l++;
            }
            set.insert(s[r]);
            res = max(res, r-l+1);
        }
        return res;
    }
};
