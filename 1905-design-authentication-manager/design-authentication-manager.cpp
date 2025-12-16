class AuthenticationManager {
    //things we need to design are basically a map to store the tokenID and their expiry time
    unordered_map<string, int>tokenMap;
    int timeToLive;
public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive=timeToLive;
        
    }
    
    void generate(string tokenId, int currentTime) {
        tokenMap[tokenId]=currentTime+timeToLive;
        
    }
    
    void renew(string tokenId, int currentTime) {
        auto it=tokenMap.find(tokenId);
        if(it!=tokenMap.end())
        {
            if(it->second>currentTime)
            {
                it->second=currentTime+timeToLive;
            }
        }

        
        
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count=0;
        for(auto &i: tokenMap)
        {
            if(i.second>currentTime)
            {
                count++;
            }

        }

        return count;
        
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */