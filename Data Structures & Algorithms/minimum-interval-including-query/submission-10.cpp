class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int, int> mp;
        vector<int> order;

        // saving orginal order for the queries..
        for(auto it : queries){
            mp[it] = -1;
        }

        for(auto it : queries){
            order.push_back(it);
        }
        sort(queries.begin(), queries.end());
        sort(intervals.begin(), intervals.end());

        // min heap for for --- min interval, end value
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        // k is traversing the intervals array..
        // i is traversing the queries array..
        int k = 0;
        for(int i = 0; i< queries.size(); i++){
            while(k < intervals.size() && intervals[k][0] <= queries[i]){
                heap.push({intervals[k][1]- intervals[k][0] + 1, intervals[k][1]});
                k++;
            }

            while(!heap.empty() && heap.top().second < queries[i]){
                heap.pop();
            }
            if (heap.empty()){
                continue;
            }
            mp[queries[i]] = heap.top().first;

        }

        vector<int> ans;
        for(int i = 0; i< order.size(); i++){
            ans.push_back(mp[order[i]]);
        }

        return ans;


    }
};
