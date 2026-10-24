class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;

        for (const string& word : strs) {
            encoded += static_cast<char>(word.size());
            encoded += word;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {
            int len = static_cast<unsigned char>(s[i]);
            i++; // move past stored length byte

            ans.push_back(s.substr(i, len));
            i += len; // move past the word
        }

        return ans;
    }
};