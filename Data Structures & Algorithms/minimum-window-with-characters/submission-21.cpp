class Solution {
public:
    string minWindow(string s, string t) {
        // freq count of t
        unordered_map<char, int> mp1;
        for(char c : t){
            mp1[c]++;
        }

        int l = 0;
        int need = mp1.size();
        int curr = 0;

        int beststart = -1;
        int bestlength = INT_MAX;

        // freq count of s
        unordered_map<char, int> mp2;
        
        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            mp2[c]++;

            // curr incr condition
            if(mp1.count(c) && mp1[c] == mp2[c]){
                curr++;
            }
            // shrinking window & calculating best answer simult...
            while(curr == need){
                if (r-l+1 < bestlength){
                    bestlength = r-l+1;
                    beststart = l;
                }

                mp2[s[l]]--;
                if(mp1.count(s[l]) && mp2[s[l]] < mp1[s[l]]){
                    curr--;
                }
                l++;
            }
        }

        return bestlength == INT_MAX ? "" : s.substr(beststart, bestlength);
    }
};
