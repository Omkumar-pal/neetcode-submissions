class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int, int> mp;
        vector<int> order;


        //saving the original order in a seperate array..
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
            // appending interval lenght & end time with all the intervals whose start time is <= queries..
            while(k < intervals.size() && intervals[k][0] <= queries[i]){
                heap.push({intervals[k][1]- intervals[k][0] + 1, intervals[k][1]});
                k++;
            }

            // now making heap top to point on the end time which is the minimum of lenght 
            // by poping all the end time which is smaller then queries[i] as that interval doesnt contain my queries, thus if any interval end is encountered whoese end time is >= queries that will certainly be my ans as heap is min and heap is ordered by min interval length..if heap is empy while searching for the ans than that will confirm the queries is not their in the intervals..
            while(!heap.empty() && heap.top().second < queries[i]){
                heap.pop();
            }

            // if heap is empty continue.. by appending the relevant mp[queires[i]]  with -1;
            if (heap.empty()){
                mp[queries[i]] = -1;
                continue;
            }
            // otherwise the heap top is my interval lenth heap.top().first..
            mp[queries[i]] = heap.top().first;

        }


        // result ans;
        vector<int> ans;
        // traversing the order array for maintaing the order and pushing the relevant ans from map using o(1) lookup..
        for(int i = 0; i< order.size(); i++){
            ans.push_back(mp[order[i]]);
        }

        return ans;


    }
};
