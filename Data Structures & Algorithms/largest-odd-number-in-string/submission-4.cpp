class Solution {
public:
    string largestOddNumber(string num) {
        int i = 0;
        int j = 0;
        int n = num.length();
        int maxi = -1;

        while (j < n) {
            int curr = num[j] - '0';

            if (curr % 2 != 0) {
                maxi = j;
            }

            j++;
        }

        if (maxi == -1) return "";

        return num.substr(i, maxi + 1);
    }
};