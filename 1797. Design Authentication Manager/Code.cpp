class AuthenticationManager {
public:
    unordered_map<string, int >mp;
    int ttl;
    AuthenticationManager(int timeToLive) : ttl(timeToLive){}
    	
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.count(tokenId) && currentTime - mp[tokenId] < ttl)
            mp[tokenId] = currentTime; // renew if condition is satisfied
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        for(auto& token:mp)
            if(currentTime - token.second < ttl) cnt++;
        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */