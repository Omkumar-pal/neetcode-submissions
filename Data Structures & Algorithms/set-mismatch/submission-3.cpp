class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n + 1, 0);
        for(int i = 0; i< nums.size(); i++){
            hash[nums[i]]++;
        }
        vector<int> res(2, 0);
        for(int i = 1; i< n + 1; i++){
            if (hash[i] == 2){
                res[0] = i;
            }
            if (hash[i] == 0){
                res[1] = i;
            }
        }
        return res;
    }
};