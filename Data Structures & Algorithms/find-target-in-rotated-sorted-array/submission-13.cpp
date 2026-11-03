class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l < r){
            int m = l + (r-l)/2;
            if (nums[m] > nums[r]){
                l = m + 1;
            }else {
                r = m;
            }
        }

        // l--> my deflection point.
        r = nums.size()-1;
        if(target < nums[l]){
            return -1;
        }
        if (l!= 0 && target > nums[r] && target <= nums[l-1]){
            r = l-1;
            l = 0;
        }

        while(l <= r){
            int m = l + (r-l)/2;
            if (target == nums[m]){
                return m;
            }else if (target < nums[m]){
                r = m-1;
            }else {
                l = m+1;
            }
        }
        return -1;
    }
};
