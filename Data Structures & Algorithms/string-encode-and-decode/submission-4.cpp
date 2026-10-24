class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(const auto &it : strs){
            s += it;
            s += '\xFF';
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> parts;
        string part = "";
        char delimeter = '\xFF';

        for(char c : s){
            if (c == delimeter){
                parts.push_back(part);
                part = "";
            }else {
                part += c;
            }
        }
    
        return parts;        
    }
};
