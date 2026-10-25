class Solution {
public:
    string clean(string s){
        string res; 
        for(int i = 0; i < s.size(); i++){
            if (isalnum(s[i])){
                res += tolower(s[i]);
            }else{
                continue;
            }
        }
        return res;
    }
    bool isPalindrome(string s) {
        // cleaning 
        string c_s = clean(s);
        
        // palindrome check
        int i = 0;
        int j = c_s.size()-1;
        while(i <= j){
            if (c_s[i] != c_s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
