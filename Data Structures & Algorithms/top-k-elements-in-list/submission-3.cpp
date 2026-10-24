class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        int n = nums.size();
        for(int i = 0; i< nums.size(); i++){
            freq[nums[i]]++;
        }

        vector<vector<int>> bucket(n+1);
        
        for(const auto [num, count]: freq){
            bucket[count].push_back(num);
        }

        vector<int> ans;
        for(int i = n; i>=1 && k > 0;i--){
            if (k == 0) break;
            if (bucket[i].empty()){
                continue;
            }
            for(auto it : bucket[i]){
                if (k == 0) break;
                ans.push_back(it);
                k--;
            }
        }
        return ans;

    }
};
