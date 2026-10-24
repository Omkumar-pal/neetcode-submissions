class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int sum = 0;
        for(int i = 0; i< nums.size()-1; i++){
            sum = nums[i];
            
            for(int j = i+1; j< nums.size(); j++){
                if (sum + nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return {};
    }
};
