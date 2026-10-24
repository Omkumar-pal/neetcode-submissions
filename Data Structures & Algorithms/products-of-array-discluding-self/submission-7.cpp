class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sfx(nums.size(), 1);
        vector<int> pfx(nums.size(), 1);
        int n = nums.size();
        int pf = nums[0];
        for(int i = 1; i < nums.size(); i++){
            pfx[i] = pfx[i-1]*pf;
            pf = nums[i];
        }

        int sf = 1;
        for(int i = n-2; i >= 0; i--){
            sf = nums[i+1];
            sfx[i] = sfx[i+1]*sf;
        }

        for(int i = 0; i< nums.size(); i++){
            pfx[i] = pfx[i]*sfx[i];
        }
        return pfx;
    }
};
