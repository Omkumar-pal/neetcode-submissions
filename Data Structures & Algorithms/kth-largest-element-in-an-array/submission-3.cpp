class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i = 0; i< nums.size(); i++){
            heap.push(nums[i]);
            if (heap.size() > k){
                heap.pop();
            }
        }
        if (heap.size() == 0) return 0;
        return heap.top();
    }
};
