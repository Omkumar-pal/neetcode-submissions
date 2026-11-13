class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> heap;
        queue<pair<int, int>> q;
        vector<int> task(26, 0);
        // populating freq
        for(int i = 0; i< tasks.size(); i++){
            task[tasks[i]-'A']++;
        }
        // pushing val to heap
        for(int i = 0; i< 26; i++){
            if (task[i] > 0){
                heap.push(task[i]);
            }
        }
        int time = 0;
        while(!heap.empty() || !q.empty()){
            if (!q.empty() && q.front().second <= time){
                    heap.push(q.front().first);
                q.pop();
            }else {
                time++;
                if (heap.empty()) continue;
                int freq = heap.top();
                heap.pop();
                if(freq-1 == 0) continue;
                q.push({freq-1, time + n});
            }
        }
        return time;
    }
};
