class Solution {
public:
    int maxScore(string s) {
        int res = 0;
        for(int i = 1; i< s.size(); i++){
            int left_zero = 0, right_one = 0;
            for(int j = 0; j < i; j++){
                if (s[j] == '0'){
                    left_zero++;
                }
            }
            for(int j = i; j < s.size(); j++){
                if (s[j] == '1'){
                    right_one++;
                }
            }

            res = max(res, left_zero + right_one);
        }
        return res;
    }
};