class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        vector<int> l_h(height.size());
        vector<int> r_h(height.size());
        l_h[0] = height[0];
        for(int i = 1; i< height.size(); i++){
            l_h[i] = max(l_h[i-1], height[i]);
        }
        r_h[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2; i >= 0; i--){
            r_h[i] = max(r_h[i+1], height[i]);
        }


        int ans = 0;
        for(int i = 0; i< height.size(); i++){
            int l_max = l_h[i];
            int r_max = r_h[i];
            ans += min(l_max, r_max)- height[i];
        }
        return ans;
    }
};
