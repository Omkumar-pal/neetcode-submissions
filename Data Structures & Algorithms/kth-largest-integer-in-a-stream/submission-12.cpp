class KthLargest {
public:
    // Min heap
    priority_queue<int, vector<int>, greater<int>> heap;
    int k = 0;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0; i< nums.size(); i++){
            heap.push(nums[i]);
            if(heap.size() > k){
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > k){
            heap.pop();
        }
        return heap.top();
    }
};
