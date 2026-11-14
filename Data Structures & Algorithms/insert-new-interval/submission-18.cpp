class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) return {newInterval};
        int l = 0;
        int r = intervals.size();
        while(l < r){
            int m = l + (r-l)/2;
            if (intervals[m][0] >= newInterval[0]){
                r = m;
            }else {
                l = m + 1;
            }

        }
        intervals.insert(intervals.begin() + l, newInterval);
        
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;
        
        while(i < n){
            int k = i + 1;
            while(k < n && intervals[i][1] >= intervals[k][0]){
                k++;
                intervals[i][1] = max(intervals[i][1], intervals[k-1][1]);
            }
            
            ans.push_back(intervals[i]);
            i = k;
        }

        //return 
        return ans;
    }
};
