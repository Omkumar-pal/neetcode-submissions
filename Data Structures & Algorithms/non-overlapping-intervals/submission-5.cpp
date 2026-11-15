class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int i = 0;
        int n = intervals.size();
        int ans = 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        while (i < n) {
            int k = i + 1;
            while (k < n && intervals[i][1] > intervals[k][0]) {
                ans++;
                k++;
            }
            i = k;
        }
        return ans;
    }
};
