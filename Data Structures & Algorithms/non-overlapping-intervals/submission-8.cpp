class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int i = 0;
        int n = intervals.size();
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];

        for(int i = 1; i< intervals.size(); i++){
            if (intervals[i][0] >= prevEnd){
                prevEnd = intervals[i][1];
            }else{
                ans++;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
        }
        return ans;
    }
};
