/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start(intervals.size(), 0);
        vector<int> end(intervals.size(), 0);
        int i = 0;
        for(auto it : intervals){
            start[i] = it.start;
            end[i] = it.end;
            i++;
        }
        sort(end.begin(), end.end());
        sort(start.begin(), start.end());
        int s = 0;
        int e = 0;
        int count  = 0;
        int res = 0;
        while(s < intervals.size()){
            if (start[s] < end[e]){
                count++;
                s++;
            }else {
                count--;
                e++;
            }
            res = max(res, count);
        }
        return res;

    }
};
