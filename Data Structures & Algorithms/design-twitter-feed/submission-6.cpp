class Twitter {
public:
    int time = 0;
    unordered_map<int, queue<pair<int, int>>> posts_id_p_u;
    unordered_map<int, unordered_set<int>> users_map;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if (posts_id_p_u.find(userId) != posts_id_p_u.end()){
            if (posts_id_p_u[userId].size() >= 10){
                posts_id_p_u[userId].pop();
            }
        }
        posts_id_p_u[userId].push({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        vector<int> userIds;
        userIds.push_back(userId);

        // collecting all valid users
        for(auto it : users_map[userId]){
            userIds.push_back(it);
        }

        // collecting all posts from every user in posts map
        vector<pair<int, int>> posts;
        for(auto it : userIds){
            queue<pair<int, int>> q;
            q = posts_id_p_u[it];
            while(!q.empty()){
                posts.push_back(q.front());
                q.pop();
            }
        }

        // no need worry about second element as time is uniqe for each posts
        // now collecting all posts in heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;   
        for(int i =0; i< posts.size(); i++){
            heap.push(posts[i]);
            if (heap.size() > 10){
                heap.pop();
            }
        }

        // adding 10 relevant ans to the ans
        while(!heap.empty()){
            ans.push_back(heap.top().second);
            heap.pop();
        }

        // return reverse ans;
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId){
            users_map[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (users_map.find(followerId) != users_map.end() && users_map[followerId].find(followeeId) != users_map[followerId].end() && followerId != followeeId){
            users_map[followerId].erase(followeeId);
        }
    }
};
