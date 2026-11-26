class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        vector<int> freq(1001, 0);

        for (int i = 0; i < hand.size(); i++) {
            freq[hand[i]]++;
        }
        int i = 0;

        for (int i = 0; i < 1001; i++) {
            while (freq[i] > 0) {
                for (int k = i; k < i + groupSize; k++) {
                    if (freq[k] > 0) {
                        freq[k]--;
                    } else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
