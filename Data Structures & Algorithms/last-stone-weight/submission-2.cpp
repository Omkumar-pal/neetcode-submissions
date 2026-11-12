class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(int i = 0; i< stones.size(); i++){
            heap.push(stones[i]);
        }
        if (heap.size() == 1) return stones[0];
        while(heap.size() > 1 && heap.size() != 0){
            int x = heap.top();
            heap.pop();
            int y = heap.top();
            heap.pop();

            if (x == y) continue;
            if (x > y){
                heap.push(x-y);
            } 
            if (x < y) {
                heap.push(y-x);
            }
        }
        if (heap.size() == 0) return 0;
        return heap.top();
    }
};
