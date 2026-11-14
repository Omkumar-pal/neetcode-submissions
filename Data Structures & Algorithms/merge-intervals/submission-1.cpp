class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int i = 0; 
        int n = intervals.size();
        while(i < n){
            int k = i + 1;
            while(k < n && intervals[i][1] >= intervals[k][0]){
                intervals[i][1] = max(intervals[i][1], intervals[k][1]);
                k++;
            }
            ans.push_back(intervals[i]);
            i = k;
        }
        return ans;
    }
};
