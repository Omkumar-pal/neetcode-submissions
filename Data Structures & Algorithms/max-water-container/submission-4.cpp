class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int i = 0;
        int j = heights.size()-1;
        while(i < j){
            int h1 = heights[i];
            int h2 = heights[j];
            int area = (j-i)*min(h1, h2);
            max_area = max(area, max_area);
            if (h1 < h2){
                i++;
            }else if(h1 > h2){
                j--;
            }else {
                i++;
            }
        }
        return max_area;
    }
};
