class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;
        for(int num : nums){
            // if num-1 exist that means it is not the starting point for seq
            // if num-1 exist that meas it is the start point of seq
            if (set.find(num-1) == set.end()){
                int length = 1;
                while(set.find(num + length) != set.end()){
                    length++;
                }
                longest = max(longest, length);
            }
        }
        
    
        return longest;
    }
};
