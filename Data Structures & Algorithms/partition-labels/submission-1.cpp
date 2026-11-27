class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> freq;
        for(char &c : s){
            freq[c-'a']++;
        }
        vector<int> ans;
        int i = 0;
        int j = 0;
        unordered_set<char> st;
        st.insert(s[0]);
        while(j < s.size()){
            while(j <s.size() && !st.empty()){
                if (st.count(s[j]) && freq[s[j]-'a'] > 0){
                    freq[s[j]-'a']--;
                    if (freq[s[j]-'a'] == 0){
                        st.erase(s[j]);
                    }
                    j++;
                }else {
                    st.insert(s[j]);
                }
            }
            ans.push_back(j-i);
            i = j;
            if (i >= s.size()) break;
            st.insert(s[j]);
        }

        return ans;

    }
};
