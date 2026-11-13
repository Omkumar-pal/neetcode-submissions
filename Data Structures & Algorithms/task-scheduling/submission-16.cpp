
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> heap;
        queue<pair<int, int>> q;

        vector<int> task(26, 0);

        // Count task frequencies
        for (char c : tasks) {
            task[c - 'A']++;
        }

        // Populate max heap
        for (int freq : task) {
            if (freq > 0) {
                heap.push(freq);
            }
        }

        int time = 0;

        while (!heap.empty() || !q.empty()) {

            // Release all tasks whose cooldown has expired
            while (!q.empty() && q.front().second <= time) {
                heap.push(q.front().first);
                q.pop();
            }

            if (heap.empty()) {
                // Jump to the next available task
                time = q.front().second;
                continue;
            }

            // Execute the most frequent task
            int freq = heap.top();
            heap.pop();

            time++;

            // If occurrences remain, put task in cooldown
            if (freq - 1 > 0) {
                q.push({freq - 1, time + n});
            }
        }

        return time;
    }
};
