class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for(string s : strs){
            int length = s.size();
            encoded_string += (char) length;
            encoded_string += s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i =0;

        while(i < s.size()){
            int len = (int)(unsigned char) s[i];
            i++;
            string ss = s.substr(i, len);
            ans.push_back(ss);
            i += len;
            
        }
        return ans;
    }
};
