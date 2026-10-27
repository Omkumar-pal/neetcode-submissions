class Solution {
   public:
    int longestPalindrome(string s) {
        
        unordered_map<int, int>mp;
        for(auto const &c : s){
            mp[c]++;
        }
        int ans= 0;
        int odd = 1;
        for(auto it: mp){
            if (it.second%2 == 0){
                ans += it.second;
            }else if (it.second % 2 != 0 && odd == 1){
                ans += ((it.second)/2)*2;
                ans += 1;
                odd--;
            }else {
                ans += (it.second/2)*2;
            }
        }
        return ans;
    }
};