class KthLargest {
   public:
    stack<int> st;
    priority_queue<int> heap;
    int k = 0;
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            heap.push(nums[i]);
        }
        this->k = k;
    }

    int add(int val) {
        int ans = 0;
        heap.push(val);
        for (int i = 1; i <= k; i++) {
            if (i == k) {
                ans = heap.top();
            }
            st.push(heap.top());
            heap.pop();
        }
        while (!st.empty()) {
            heap.push(st.top());
            st.pop();
        }
        
        return ans;
    }
};
