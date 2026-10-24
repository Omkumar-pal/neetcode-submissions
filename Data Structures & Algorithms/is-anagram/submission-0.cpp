class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        if (s.size() != t.size()){
            return false;
        }

        for(int i = 0; i< s.size(); i++){
            mp[s[i]]++;
        }

        for(int i = 0; i< s.size(); i++){
            if (mp.count(t[i])){
                mp[t[i]]--;
            }else{
                return false;
            }
        }

        for(auto it : mp){
            if (it.second != 0){
                return false;
            }
        }
        return true;
    }
};
