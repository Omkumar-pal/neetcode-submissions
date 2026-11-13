class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> heap;
        queue<pair<int, int>> q;
        vector<int> arr(26, 0);
        // filling heap
        for (int i = 0; i< tasks.size(); i++) {
            arr[tasks[i]-'A']++;
        }

        for(int i =0; i < 26; i++){
            if (arr[i] > 0){
                heap.push(arr[i]);
            }
        }

        int time = 0;
        while (!heap.empty() || !q.empty()) {
            if (!q.empty() && q.front().second <= time) {
                pair<int,int> x = q.front();
                q.pop();
                heap.push(x.first);
                
            } else {
                time++;
                if (heap.empty()) continue;
                int freq = heap.top();
                heap.pop();
                
                if (freq-1 == 0) continue;
                q.push({freq - 1, time + n});
            }
        }
        return time;
    }
};
