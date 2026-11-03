class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if (it != mp.end()){
            const auto &value = it->second;
            int l = 0;
            int r = value.size()-1;

            while(l <= r){
                int m = l + (r-l)/2;
                if (value[m].first == timestamp){
                    return value[m].second;
                }else if(value[m].first < timestamp){
                    l = m + 1;
                }else {
                    r = m-1;
                }
            }
            return r >= 0 ? value[r].second : "";
        }
        return "";
    }
};
