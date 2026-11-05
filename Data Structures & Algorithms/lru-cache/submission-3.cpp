class LRUCache {
public:
    unordered_map<int, int> mp;
    vector<pair<int,int>> cache;
    int cap = 0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // when key is in map
        if(mp.find(key) != mp.end()){
            for(int i = 0; i< cache.size(); i++){
                if (cache[i].first == key){
                    cache.erase(cache.begin()+i);
                    cache.push_back({key, mp[key]});
                    break;
                }
            }
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        // if existing key, value is updated then, update my priority & mp {Key , value }
        if (mp.find(key) != mp.end()){
            for(int i = 0; i< cache.size(); i++){
                if (cache[i].first == key){
                    cache.erase(cache.begin()+i);
                    cache.push_back({key, value});
                    break;
                }
            }
            mp[key] = value;

        }else 
        // when key is not found in map
        {
            // if map is at its capacity i should remove LFE...& add it in cache
            if (mp.size() >= cap){
                mp.erase(cache[0].first);
                cache.erase(cache.begin());
                mp[key] = value;
                cache.push_back({key, value});
            }else{
                // just add the {key ,value } & update cache.
                mp[key] = value;
                cache.push_back({key, value});
            }
            
        }



    }
};
