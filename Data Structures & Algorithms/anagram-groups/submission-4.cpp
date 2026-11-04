class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto it : strs){
            string s = it;
            sort(it.begin(), it.end());
            mp[it].push_back(s);
        }

        vector<vector<string>> ans;
        for(const auto &it : mp){
            ans.push_back(it.second);
        }

        return ans;


    }
};
