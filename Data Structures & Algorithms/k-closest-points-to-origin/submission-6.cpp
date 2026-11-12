class Solution {
   public:
    struct Compare {
        bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            return a.first > b.first;
        }
    };
    int distance(pair<int, int> pr) { return 1LL* pr.first* pr.first + 1LL* pr.second* pr.second; }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> heap;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        for (int i = 0; i < points.size(); i++) {
            pair<int, int> x = {points[i][0], points[i][1]};
            int d = distance(x);
            heap.push({d, x});
        }

        for (int i = 0; i < k; i++) {
            auto it = heap.top();
            ans.push_back({it.second.first, it.second.second});
            heap.pop();
        }
        return ans;
    }
};
